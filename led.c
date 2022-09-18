/** @file:      led.c
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     Led functions use in game.c to turn on and off the LED
*/

#include "pio.h"
#include "led.h"


/**
 * @brief: Turn LED on
*/
void led_on (void)
{
    pio_output_high(PC2_PIO);
}


/**
 * @brief: Turn LED off
*/
void led_off (void)
{
    pio_output_low(PC2_PIO);
}


/**
 * @brief: Initialise LED
*/
void led_init (void)
{
    pio_config_set(PC2_PIO, PIO_OUTPUT_HIGH);
}
