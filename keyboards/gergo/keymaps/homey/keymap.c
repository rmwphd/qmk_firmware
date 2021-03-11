/* rmw-stylez
 */

#include QMK_KEYBOARD_H

enum user_layers {
   ALPHA1 = 0
  ,ALPHA2R
  ,ALPHA2L
  ,ALPHA3R
  ,ALPHA3L
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPHA1] = LAYOUT_stacked(
    _______,    _______,_______,_______,_______,_______,                               
    _______,    KC_A,  KC_S, LT(ALPHA3L,KC_D), LT(ALPHA2L,KC_F), KC_G, _______,         
    _______,    _______,_______,_______,_______,_______, KC_TAB  , KC_ESCAPE,   
                                      S(KC_LGUI), KC_LALT,  KC_BSPACE, OSM(MOD_LSFT),

                          _______,_______,_______,_______,_______,  KC_DEL,
             _______,  KC_H,   LT(ALPHA2R,KC_J),  LT(ALPHA3R,KC_K),    KC_L,    KC_SCLN, KC_QUOTE,
    KC_CAPS, KC_B      ,  _______,_______,_______,_______,_______, _______,
    KC_ENT,  KC_SPACE   , KC_RGUI, KC_RCTL
    ),

[ALPHA2L] = LAYOUT_stacked(
    _______,    _______,_______,_______,_______,_______,                               
    _______,    _______,  KC_TILD,  KC_EXLM, _______,_______,_______,              
    _______,    _______,_______,_______,_______,_______, KC_TAB  , KC_ESCAPE,   
                                      S(KC_LGUI), KC_LALT,  KC_BSPACE, OSM(MOD_LSFT),

                          _______,_______,_______,_______,_______,  KC_DEL,
             _______,  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, KC_QUOTE,
    KC_CAPS, KC_B      ,  _______,_______,_______,_______,_______, _______,
    KC_ENT,  KC_SPACE   , KC_RGUI, KC_RCTL
    ),

[ALPHA2R] = LAYOUT_stacked(
    _______,    _______,_______,KC_LBRC,KC_RBRC,_______,                               
    _______,    KC_Q,  KC_W,  KC_E,  KC_R, KC_T,_______,              
    _______,    _______,_______, KC_LBRC, KC_RBRC, _______, KC_TAB  , KC_ESCAPE,   
                                      S(KC_LGUI), KC_LALT,  KC_BSPACE, OSM(MOD_LSFT),

                          _______,_______,_______,_______,_______,  KC_DEL,
             _______,  _______, _______,KC_QUES,  KC_SLASH, KC_COLON, KC_QUOTE,
    KC_CAPS, KC_B      ,  _______,_______,_______,_______,_______, _______,
    KC_ENT,  KC_SPACE   , KC_RGUI, KC_RCTL
    ),

[ALPHA3L] = LAYOUT_stacked(
    _______,     _______,_______,_______,_______,_______,     
    _______,     _______,  _______,  _______, KC_DOT, _______, _______,
    _______,       _______,_______,_______,_______,_______, KC_TAB  , KC_ESCAPE,  
                                        S(KC_LGUI), KC_LALT,  KC_BSPACE, OSM(MOD_LSFT),

                          _______,_______,_______,_______,_______, KC_DEL,
             _______,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_QUOTE,
    KC_CAPS, KC_B      ,  _______,_______,_______,_______,_______, _______,
    KC_ENT,  KC_SPACE   , KC_RGUI, KC_RCTL
    ),

[ALPHA3R] = LAYOUT_stacked(
    _______,     _______,_______,_______,_______,_______,                           
    _______,     KC_Z,  KC_X,  KC_C, KC_V, KC_B, _______,              
    _______,       _______,_______,_______,_______,_______, KC_TAB  , KC_ESCAPE,  
                                        S(KC_LGUI), KC_LALT,  KC_BSPACE, OSM(MOD_LSFT),

                          _______,_______,_______,_______,_______, KC_DEL,
             _______,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_QUOTE,
    KC_CAPS, KC_B      ,  _______,_______,_______,_______,_______, _______,
    KC_ENT,  KC_SPACE   , KC_RGUI, KC_RCTL
    )
};


