/*
 * radio.h
 *
 *  Created on: Jun 27, 2018
 *      Author: george
 */

#ifndef RADIO_H_
#define RADIO_H_

#include <stdint.h>
#include <rfm75.h>
#include "badge.h"

#define RADIO_MSG_TYPE_BEACON 1
#define RADIO_MSG_TYPE_BOOP 2
#define RADIO_MSG_TYPE_ACK 3

#define RADIO_PROTO_VER 1

// We beacon every 8 seconds, so our sliding window will be 112*8 seconds = about 15 minutes
#define RADIO_WINDOW_BEACON_COUNT 112

#define FREQ_MIN 14
#define FREQ_NUM 6

typedef struct {
    uint8_t intervals_left : 8;
} badge_info_t;

typedef struct {
    /// This badge's id
    uint16_t badge_id;
    /// Protocol version
    uint8_t proto_version;
    /// Message opcode
    uint8_t msg_type;
    /// Optionally-used 1-byte message payload
    uint8_t msg_payload;
    uint16_t crc16;
} radio_proto_t;

extern radio_proto_t curr_packet_tx;
extern badge_info_t ids_in_range[BADGES_IN_SYSTEM];

extern uint16_t rx_cnt[FREQ_NUM];
extern uint8_t radio_frequency;
extern uint8_t radio_frequency_done;

// TODO: Figure out why I have to do this.
typedef void rfm75_rx_callback_fn(uint8_t* data, uint8_t len, uint8_t pipe);
typedef void rfm75_tx_callback_fn(uint8_t ack);

rfm75_rx_callback_fn radio_rx_done;
rfm75_tx_callback_fn radio_tx_done;
void radio_init(uint16_t addr);
void radio_boop(uint8_t badge_id, uint8_t seq);
void radio_interval();
void radio_event_beacon();

#endif /* RADIO_H_ */
