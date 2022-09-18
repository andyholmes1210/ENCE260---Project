/** @file:      speaker.h
    @author:    Tawatchai Holmes (Andy) tho78, Zhedong Cao (Barry) zca19
    @date:      15 OCT 2020
    @brief:     Speaker function in .h format
*/

#ifndef SPEAKER_H
#define SPEAKER_H

#include "system.h"
#include "pio.h"
#include "pacer.h"

#define PIEZO1_PIO PIO_DEFINE (PORT_D, 4)
#define PIEZO2_PIO PIO_DEFINE (PORT_D, 6)


/**
 * @brief: Initilise speaker
*/
void init_speaker(void);


/**
 * @brief: Output sound from speaker
*/
void use_speaker(void);

#endif
