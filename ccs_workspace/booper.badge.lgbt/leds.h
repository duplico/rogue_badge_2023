/*
 * leds.h
 *
 *  Created on: Jul 31, 2023
 *      Author: george
 */

#ifndef LEDS_H_
#define LEDS_H_

#include <stdint.h>

typedef struct {
    uint8_t tl : 1;
    uint8_t l : 1;
    uint8_t bl : 1;
    uint8_t m : 1;
    uint8_t dot : 1;
    uint8_t tr : 1;
    uint8_t r : 1;
    uint8_t br : 1;
} eye_t;

typedef struct {
    eye_t eyes[2];
    uint8_t dur;
    uint8_t last_frame;
} eye_anim_frame_t;

extern uint16_t leds_scan_speed;

void leds_timestep();
void leds_blink_or_bling();
void leds_init();

#endif /* LEDS_H_ */
