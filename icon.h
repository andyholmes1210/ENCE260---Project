/** @file:      icon.h
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     icon functions in .h format
*/

#ifndef ICON_H
#define ICON_H

#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"


/**
 * @brief: Define PIO pins driving LED matrix rows.
*/

static const pio_t rows[];


/**
 * @brief: Define PIO pins driving LED matrix columns.
*/

static const pio_t cols[];


/**
 * @brief: Initilise the LED Metrics
*/

void ledm_init(void);


/**
 * @brief: Display the LED on screen
 * @param: row partterns
 * @param: current column
*/
void display_column(uint8_t row_pattern, uint8_t current_column);


#endif
