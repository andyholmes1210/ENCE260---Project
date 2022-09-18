/** @file:      compare.c
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     compare functions use in game.c
*/

#include "system.h"


/**
 * @brief: Comparing the 2 different choices from each of the player
 * @param: Player_1 choice
 * @param: Player_2 choice
 * @return: Return 0 if player1 wins, 1 otherwise.
*/
int compare_choice(uint8_t Player_1, uint8_t Player_2)
{
    if (Player_1 == 0) {
        if (Player_2 == 2 || Player_2 == 3) {
            return 0;
        } else {
            return 1;
        }
    } else if (Player_1 == 1) {
        if (Player_2 == 0 || Player_2 == 4) {
            return 0;
        } else {
            return 1;
        }
    } else if (Player_1 == 2) {
        if (Player_2 == 1 || Player_2 == 4) {
            return 0;
        } else {
            return 1;
        }
    } else if (Player_1 == 3) {
        if (Player_2 == 1 || Player_2 == 2) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (Player_2 == 0 || Player_2 == 3) {
            return 0;
        } else {
            return 1;
        }
    }
}
