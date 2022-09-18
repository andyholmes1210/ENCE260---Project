/** @file:      start.c
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     Display text at the beginning of the game in game.c
*/


#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"

/**
 * @brief: Display start screen
 * @param: word characters
*/
int words_display (char* words)
{
    system_init();
    navswitch_init ();

    tinygl_init (500);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (20);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(words);

    pacer_init (500);

    while(1) {
        pacer_wait();
        navswitch_update ();
        tinygl_update();
        if (navswitch_push_event_p (NAVSWITCH_NORTH) || navswitch_push_event_p (NAVSWITCH_EAST)
        || navswitch_push_event_p (NAVSWITCH_WEST) || navswitch_push_event_p (NAVSWITCH_SOUTH)
        || navswitch_push_event_p (NAVSWITCH_PUSH)){
            return 0;
        }
    }
}
