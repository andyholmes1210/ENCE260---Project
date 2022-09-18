/** @file:      game.c
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     Compare both of the players selection and determine which player wins
    @brief:     by displaying "Winner" or "Loser" text after one of the player wins 3 games and each round.

The game is similar to the normal Rock, Paper and Scissor, but instead
of 3 options we got 5 options to choose from between the player

-Sword
-Shield
-Human
-Gun
-Grenade

Each options consist of 2 wins and 2 loss

-Sword beats Grenade and Shield, but lose to Gun and Human
-Shield beats Gun and Human, but lose to Sword and Grenade
-Human beats Gun and Sword, but lose to Shield and Grenade
-Gun beats Grenade and Sword, but lose to Shield and Human
-Grenade beats Human and Shield, but lose to Sword and Gun


*/



#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "button.h"
#include "led.h"
#include "speaker.h"
#include "compare.h"
#include "start.h"
#include "icon.h"


/**
 * @brief:Different choices for the game
*/
static const uint8_t bitmap[] = {
    0x00, 0x10, 0x3E, 0x10, 0x00,      //Sword
    0x00, 0x1E, 0x3E, 0x1E, 0x00,      //Shield
    0x00, 0x28, 0x1C, 0x28, 0x00,      //Human
    0x04, 0x04, 0x0C, 0x04, 0x1C,      //Gun
    0x00, 0x38, 0x3E, 0x3A, 0x00       //Grenade
};


/**
 * @brief: Display the letter 'W'
*/
static const uint8_t winner_screen[] = {
    0x0E, 0x30, 0x0E, 0x30, 0x0E
};


/**
 * @brief: Display the letter 'L'
*/
static const uint8_t loser_screen[] = {
    0x00, 0x3E, 0x20, 0x20, 0x00
};


/**
 * @brief: Display the letter 'S'
*/
static const uint8_t equal_screen[] = {
    0x00, 0x24, 0x2A, 0x12, 0x00
};

/**
 * @brief: Display 'W' on Winner screen if the player wins
 * @brief: Display 'L' on Loser screen if the player loss
 * @brief: Display 'S' on both of the screen when both of the player
 * @brief: have the same choice
 * @param: Player_1 choice
 * @param: current_column
 * @param: key
*/
static int result_display(uint8_t Player_1, uint8_t current_column, char key)
{
    while (1) {
        pacer_wait();
        navswitch_update();
        if (key == 'W') {
            display_column (winner_screen[current_column], current_column);
        } else if (key == 'L') {
            display_column (loser_screen[current_column], current_column);
        } else if (key == 'S') {
            display_column (equal_screen[current_column], current_column);
        }
        current_column++;

        if (current_column == 5) {
            current_column = 0;
        }
        if (button_pressed_p()) {
            ir_uart_putc (Player_1 + 1);
        }
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            return 0;
        }
    }
}


/**
 * @brief: Compare both of the input that both of the player have chose and then
 * @brief: determine which of the player wins/lose or tie by the if's statement and
 * @brief: determine the display winner_display, loser_display or equal_display by the
 * @brief: player's choice and has a time out function
 * @param: Player_1 choice
 * @param: current_column
*/
static int determine_outcome(uint8_t Player_1, uint8_t current_column)
{
    uint8_t Player_2;
    ledm_init();
    while(1) {
        pacer_wait();

        if (button_pressed_p()) {
            ir_uart_putc (Player_1 + 1); //Encode
        }
        if (ir_uart_read_ready_p()) {
            Player_2 = ir_uart_getc() - 1; //Decode
            if (Player_2 != 0 && Player_2 != 1 && Player_2 != 2 && Player_2 != 3 && Player_2 != 4) { //Check index
                continue;
            } else if (Player_1 == Player_2) {
                result_display(Player_1, current_column, 'S');
                return 0;
            } else if (compare_choice(Player_1, Player_2) == 0) {
                result_display(Player_1, current_column, 'W'); //Player_1 win
                return 1;
            } else {
                result_display(Player_1, current_column, 'L'); //Player_2 win
                return 0;
            }
        }
        current_column++;
        if (current_column == 5) {
            current_column = 0;
        }
    }
}


int main (void)
{
    uint8_t Player_1 = 0;
    uint8_t current_column = 0;
    uint16_t number = 0;

    system_init ();
    pacer_init (500);
    navswitch_init ();
    button_init ();
    ir_uart_init ();
    led_init ();
    ledm_init();
    init_speaker();

    words_display("WELECOME TO MEDIEVAL DYNASTY, MOVIE NAVSWITCH TO START");

    while (1) {

        pacer_wait ();
        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_EAST)) { //Selection
            if (Player_1 == 4) {
                Player_1 = 0;
            } else {
                Player_1++;
            }
        }
        if (navswitch_push_event_p (NAVSWITCH_WEST)) { //Selection
            if (Player_1 == 0) {
                Player_1 = 4;
            } else {
                Player_1--;
            }
        }

        display_column(bitmap[Player_1 * 5 + current_column], current_column);
        current_column++;

        if (current_column == 5) {
            current_column = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) { //Comparision
            number += determine_outcome(Player_1, current_column);
        }
        if (number == 3) {
            ir_uart_putc ('A');
            ledm_init();
            words_display("YOU WIN!"); //Display on winner screen
            break;
        }
        if (ir_uart_read_ready_p()) {
            if (ir_uart_getc() == 'A') {
                led_off(); //Turn LED off for player who loss
                ledm_init();
                use_speaker(); //Speaker on
                words_display("YOU LOSS!"); //Display on loser screen
                break;
            }
        }
    }
}
