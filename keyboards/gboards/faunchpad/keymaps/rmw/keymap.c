#include QMK_KEYBOARD_H
// Chord Prefixes
#define MEDIA 	( FP11 | FP12 )
#define MOVE		( FP01 | FP11 )
#define NUM			( FP04 | FP14 )

#include "g/keymap_engine.h"

// this isn't really a keymap file at all. What a bummer. 
// Go look in the dicts, or config_engine.h if you want to change what keys are where....

// Though, KC_1, KC_2, etc. are linked to FP01, etc., so you can just
// move those to another layer to move the chord stuff around lol

/* 	 							  //
 *  .---------------------------//
 *	| FP01 | FP02 | FP03 | FP04 | 
 *  |---------------------------|
 *	| FP11 | FP12 | FP13 | FP14 | 
 *  '--------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_faunch(KC_1,  KC_2,  KC_3,  KC_4,
  										  KC_5,  KC_6,  KC_7,  LT(1)),
  [1] = LAYOUT_faunch(KC_8,  KC_9,  KC_A,  KC_B,
  										  KC_C,  KC_D,  KC_E,  TO(0))
  };

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
