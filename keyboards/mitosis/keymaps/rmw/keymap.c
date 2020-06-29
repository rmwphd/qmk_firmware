/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "rmw.h"
#include "mitosis.h"

#ifndef LONGPRESS_DELAY
#define LONGPRESS_DELAY 150
#endif
#ifndef LAYER_TOGGLE_DELAY
#define LAYER_TOGGLE_DELAY 300
#endif
#ifndef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 300
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_stack(
        KC_Q,     KC_W,         KC_E,      KC_R,     KC_T,
        KC_A, LT(NUMPAD,KC_S),  KC_D, LT(FSYM,KC_F), KC_G,          
        KC_Z,     KC_X,         KC_C,      KC_V,     KC_B,  
                    TO(ADJUST), TD(FRBK2), KC_TAB,   TD(AGC),  
                    OSL(EDIT),  TD(SGCA), KC_BSPACE, TD(SHNTC),  

                KC_Y,    KC_U,       KC_I,  KC_O,       KC_P,       
                KC_H, LT(JSYM,KC_J), KC_K,  KC_L,    LT(EDIT,KC_SCLN),
                KC_N, KC_M,       KC_COMM, KC_DOT,   LT(MEDIA,KC_SLSH),
                TD(GCA), TD(CTLALL),  FORM_GET,  FORM_PUT,
                SFTENT, KC_SPC,  KC_QUOT, OSL(NUMPAD)
    ),

    [NUMPAD] = LAYOUT_stack(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5 ,                       
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12, _______, _______, _______,
                 _______, _______, _______, _______,    
                 _______, _______, _______, _______,    
                                                    
                _______, KC_7,     KC_8,    KC_9,   KC_KP_MINUS,
                _______, KC_4,     KC_5,    KC_6,   KC_KP_PLUS ,
                _______, KC_1,     KC_2,    KC_3,   KC_KP_SLASH,
                _______, KC_0,   KC_DOT,    _______, 
                _______,  _______, _______, _______ 
    ),

    [EDIT] = LAYOUT_stack(
        TASK_MAN,   _______,    SELW_LEFT, SELW_RIGHT, _______,                       
        _______ , LGUI(KC_GRV), MVW_LEFT , MVW_RIGHT , _______,                  
        R_UNDO  ,   R_CUT  ,     R_COPY  , R_PASTE   , R_REDO ,  
                              _______, _______, _______, _______,
                              _______, _______, DEL_WRD, _______,

                NEW_TAB , KC_PGUP, KC_UP, KC_PGDOWN, KC_PSCREEN,
                R_HOME  , KC_LEFT, KC_DOWN, KC_RIGHT, R_END,
                SEL_HOME, S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT), SEL_END,
                _______, _______, _______, _______,
                _______, _______, _______, _______
    ),

    [ADJUST] = LAYOUT_stack(
        _______,    _______   , _______ , _______ , _______,
        TO(QWERTY), TO(EDIT)  , TO(JSYM), TO(FSYM), TO(NUMPAD),
        _______,    TO(MEDIA) , _______, _______ , _______,  
                    TO(QWERTY), _______, _______ , _______,    
                    _______   , _______, _______ , _______,    

                _______, _______, _______, _______, _______,  
                _______, _______, _______, _______, _______, 
                _______, _______, _______, _______, _______, 
                _______, _______, _______, _______,
                _______, _______, _______, _______ 
    ),

    [FSYM] = LAYOUT_stack(
        _______, _______,  _______  ,   _______, _______,                                
        _______, KC_TILD,  KC_EXLM  ,   _______, _______,                                
        _______, _______, TO(QWERTY),   _______, _______,  
                        LCTL(KC_RIGHT), _______, _______, _______,    
                            _______,    _______, _______, _______,    

                KC_CIRC,  KC_AMPR , KC_ASTR,  KC_GRV ,  _______,  
                KC_EQUAL, KC_MINUS, KC_UNDS,  KC_PIPE, KC_COLON, 
                _______,  KC_PLUS,  KC_BSLS,  KC_SLSH, _______, 
                _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______
    ), 
    
    [JSYM] = LAYOUT_stack(
        KC_GRV,  KC_AT  , KC_LCBR,     KC_RCBR,    _______,                      
        KC_HASH, KC_DLR , KC_LPRN,     KC_RPRN,    KC_LEFT,                      
        KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, _______, 
                        _______, _______, _______, _______, 
                        _______, _______, _______, _______, 

                _______, _______, _______, _______,  _______,  
                _______, _______, KC_QUES, KC_SLSH, KC_COLON, 
                _______, _______, TO(QWERTY), _______, _______, 
                _______, _______, _______, LCTL(KC_LEFT),
                _______, _______, _______, _______
    ), 
    
    [MEDIA] = LAYOUT_stack(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,
        KC_F11 , KC_F12 , _______, _______, _______,   
                 _______, _______, _______, _______, 
                 _______, _______, KC_WBAK, KC_WFWD, 

            _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______,
            _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,
            _______, _______, _______, _______, 
            KC_MPLY, KC_MPRV, KC_MNXT, _______

    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FORM_GET:
            if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code16(G(KC_A));
                tap_code16(G(KC_C));
            }
        return false;
        case FORM_PUT:
            if (record->event.pressed) {
                tap_code16(KC_MS_BTN1);
                tap_code16(G(KC_A));
                tap_code16(G(KC_V));
            }
        return false;
    }
    return true;
}



layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case QWERTY:
    set_led_off;
    break;
    case NUMPAD:
    set_led_red;
    break;
    case EDIT:
    set_led_green;
    break;
    case FSYM:
    // nothing?
    break;
    case JSYM:
    // nothing?
    break;
    case MEDIA:
    // nothing?
    break;
    case ADJUST:
    set_led_blue;
    break;
  }
  return state;
}
