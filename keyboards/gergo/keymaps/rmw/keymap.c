/* rmw-stylez
 */

#include QMK_KEYBOARD_H

#include "rmw.h"

enum user_custom_keycodes_keymap {
   SMTHG = KEYMAP_SAFE_RANGE
   ,MED_SLSH = LT(MEDIA,KC_SLSH)
   ,EDIT_SCL = LT(EDIT,KC_SCLN)
   ,NUM_S = LT(NUMPAD,KC_S)
   ,FLAYER = LT(FSYM,KC_F)
   ,JLAYER = LT(JSYM,KC_J)
   ,EDIT_BSP = LT(EDIT,KC_BSPACE)
   ,NUM_SPC = LT(NUMPAD,KC_SPC)
   ,SWP_WND = LGUI(KC_GRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT_stacked(
    TD(FRBK2),     KC_Q,  KC_W,  KC_E,  KC_R,     KC_T,                               
    OSL(EDIT),     KC_A,  NUM_S, KC_D,  FLAYER,   KC_G,     TO(EDIT),              
    DSKTP_L, KC_Z,  KC_X,  KC_C,  KC_V,     KC_B,     KC_TAB  , KC_ESCAPE,   
                                        TD(SGCA), TD(AGC),  EDIT_BSP, TD(SHENT),

                          KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
             TO(NUMPAD),  KC_H,   JLAYER,  KC_K,    KC_L,    EDIT_SCL, KC_QUOTE,
    KC_CAPS, KC_B      ,  KC_N,   KC_M,    KC_COMM, KC_DOT,  MED_SLSH, DSKTP_R,
    SFTENT,  NUM_SPC   , TD(GCA), TD(CTLALL)
    ),

[NUMPAD] = LAYOUT_stacked(
    _______, _______, _______, KC_UP  , _______, _______,                     
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT , _______,  TO(QWERTY),        
    _______, R_UNDO , R_CUT  , R_COPY , R_PASTE  , R_REDO , _______, _______,         
                                          _______, _______, _______, _______,    
    
                      _______, KC_7  , KC_8, KC_9, KC_KP_MINUS, _______, 
            TO(EDIT), _______, KC_4  , KC_5, KC_6, KC_KP_PLUS, _______, 
    _______, _______, KC_COMM, KC_1  , KC_2, KC_3, KC_KP_SLASH, _______, 
    _______, _______, KC_0   , KC_DOT
    ),

[EDIT] = LAYOUT_stacked(
    _______, TASK_MAN, _______, SELW_LEFT, SELW_RIGHT, _______,      
    _______, _______ , SWP_WND, MVW_LEFT , MVW_RIGHT , _______, TO(NUMPAD),      
    _______, R_UNDO  , R_CUT  , R_COPY   , R_PASTE   , R_REDO , _______   ,  FORM_GET,           
                                                   _______, _______, _______   ,   _______,

                                 NEW_TAB   , KC_PGUP   , KC_UP      , KC_PGDOWN, KC_PSCREEN, _______,
                     TO(QWERTY), R_HOME    , KC_LEFT   , KC_DOWN    , KC_RIGHT , R_END     , _______,
    FORM_PUT, _______, SEL_HOME, S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT), SEL_END  , _______,
    _______,  _______, _______, _______       
    ),

[FSYM] = LAYOUT_stacked(
    TO(ADJUST), _______, _______, _______, _______, _______,                   
    _______   , _______, KC_TILD, KC_EXLM, _______, _______, _______,             
    DSKTP_R   , _______, _______, _______, _______, _______, _______, _______,    
                                           _______, _______, DEL_WRD, _______,    
    
                      KC_CIRC , KC_AMPR , KC_ASTR, KC_GRV , _______ , _______,
             _______, KC_EQUAL, KC_MINUS, KC_UNDS, KC_BSLS, KC_COLON, KC_DQT ,
    _______, _______, _______,  KC_PLUS , KC_SLSH, KC_PIPE, _______ , _______,
    _______, _______, _______, _______
    ),

[JSYM] = LAYOUT_gergo(
    _______, KC_GRV,  KC_AT  , KC_LCBR,     KC_RCBR,    _______,                                            _______, _______, _______, _______, _______, TO(ADJUST),
    _______, KC_HASH, KC_DLR , KC_LPRN,     KC_RPRN,    KC_LEFT, _______,                           _______, _______, _______, KC_QUES, KC_SLSH, KC_COLON, _______, 
    _______, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, DSKTP_L, 
                                        _______, _______, _______, _______,         _______, KC_TAB, _______, _______
    ),
[MEDIA] = LAYOUT_gergo(
    TO(ADJUST), KC_MS_WH_UP, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, _______,                                             _______, _______, _______, _______, _______, _______,
    _______, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,   _______, _______,                           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, KC_MS_BTN3,         _______, _______, _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, _______, _______, 
                                        _______, _______, KC_MS_BTN1, KC_MS_BTN2,         KC_MS_BTN1, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD
    ),
[ADJUST] = LAYOUT_gergo(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
    TO(EDIT), TO(QWERTY), TO(NUMPAD), TO(JSYM), TO(FSYM), TO(MEDIA), _______,                           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______,         _______, _______, _______, _______
    )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case FORM_GET:
      if (record->event.pressed) {
        tap_code(KC_BTN1);
        tap_code16(G(KC_A));
        tap_code16(G(KC_C));
      }
      return false;
    case FORM_PUT:
      if (record->event.pressed) {
        tap_code(KC_BTN1);
        tap_code16(G(KC_A));
        tap_code16(G(KC_V));
      }
      return false;
  }
  return true;
}
