/// mini.badge.lgbt 2023 main header file.
/**
 ** This header contains the core configuration and functionality declarations
 ** and definitions for the booper.badge.lgbt badge.
 **
 ** \file badge.h
 ** \author George Louthan
 ** \date   2022
 ** \copyright (c) 2022 George Louthan @duplico. MIT License.
 */

#ifndef BADGE_H_
#define BADGE_H_

#include "stdint.h"

/// MCLK rate in MHZ.
#define MCLK_FREQ_MHZ 8
/// SMCLK rate in Hz.
#define SMCLK_RATE_HZ 8000000

/// Number of csecs for a button long-press
#define BUTTON_LONG_PRESS_CSECS 150

/// Number of possible badges in the system
#define BADGES_IN_SYSTEM 120
// TODO: This isn't great:
/// Number of bytes in the bitfield of all badge IDs
#define BADGES_SEEN_BUFFER_LEN_BYTES BADGES_IN_SYSTEM / 8 + 1
/// Valid badge ID but indicating it hasn't been assigned by a controller.
#define BADGE_ID_UNASSIGNED 250

/// Badge clock write interval in seconds. preferably a power of 2.
#define BADGE_CLOCK_WRITE_INTERVAL 16
/// Seconds a remote badge needs to be in the future to accept its clock.
#define BADGE_CLOCK_DRIFT_ALLOWED_SECONDS 300

/// Badge config struct definition
typedef struct {
    /// The badge's ID, between 0 and BADGE_ID_UNASSIGNED, inclusive.
    uint16_t badge_id;
    /// This badge's time clock, in seconds since Wednesday at noon Vegas time.
    uint32_t clock;
    /// Bitfield tracking badge IDs seen.
    uint8_t badges_seen[BADGES_SEEN_BUFFER_LEN_BYTES];
    /// Counter of badges seen generally
    uint8_t badges_seen_count;
} badge_conf_t;

extern volatile badge_conf_t badge_conf;

extern uint8_t badge_brightness_level;
extern volatile uint8_t f_time_loop;
extern volatile uint8_t f_button_press_long;
extern volatile uint8_t f_second;
extern volatile uint8_t button_state;

inline volatile void fram_unlock();
inline volatile void fram_lock();

void badge_button_press_long();
void badge_button_press_short();

#endif /* BADGE_H_ */
