#include "rmw.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
    SIFP_SIGNUP_EE = KEYMAP_SAFE_RANGE
   ,SIFP_SIGNUP_OR
   ,ANOTHER_LINK
   ,LINK_3
   ,LINK_4
   ,SHRUG
   ,DISFACE
   ,CLOUD
   ,TFLIP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_4x4(
        SIFP_SIGNUP_EE, SIFP_SIGNUP_OR, LINK_3, LINK_4,
        G(KC_TILDE),  KC_UP, _______, G(KC_RIGHT),
        KC_LEFT, KC_DOWN, KC_RIGHT, G(KC_TAB),
        CLOUD,  SHRUG,  FORM_GET, FORM_PUT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SIFP_SIGNUP_EE:
            if (record->event.pressed) {
                SEND_STRING("https://princeton.mentorcollective.org/register/princeton-sifp/mentee");
            }
            return false;
            break;
        case SIFP_SIGNUP_OR:
            if (record->event.pressed) {
                SEND_STRING("https://princeton.mentorcollective.org/register/princeton-sifp/mentor");
            }
            return false;
            break;
        case LINK_3:
            if (record->event.pressed) {
                SEND_STRING("https://princeton.zoom.us/my/ashleeshaw");
            }
            return false;
            break;
        case LINK_4:
            if (record->event.pressed) {
                SEND_STRING("http://ashleeshaw.com");
            }
            return false;
            break;
        case FORM_GET:
            if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code16(G(KC_A));  // make this (C(KC_A)) on Windows
                tap_code16(G(KC_C));  // make this (C(KC_C)) on Windows
            }
            return false;
            break;
        case FORM_PUT:
            if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code16(G(KC_A));  // make this (C(KC_A)) on Windows
                tap_code16(G(KC_V));  //  make this (C(KC_V)) on Windows
            }
            return false;
            break;
        case CLOUD:       // (っ◕‿◕)っ
            if(record->event.pressed){
                send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063");
            }
            return false;
            break;
        case SHRUG: // ¯\_(ツ)_/¯ 
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false; 
            break;
        case DISFACE:       // ಠ_ಠ 
            if(record->event.pressed){
                send_unicode_hex_string("0CA0 005F 0CA0");
            }
            return false;
            break;
        case TFLIP:         // (╯°□°)╯ ︵ ┻━┻ 
            if(record->event.pressed){
                send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
            }
            return false;
            break;
    }
    return true;
}

