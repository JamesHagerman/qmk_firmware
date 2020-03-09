/* Copyright 2019 gtips
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

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
    _BAR,
    _I3,
    _ADJUST
};

// Custom Key names
// These are for use with my i3wm config to allow me to move quickly between screens and panels
#define TERM_1 LALT(KC_1)
#define TERM_2 LALT(KC_2)
#define TERM_3 LALT(KC_3)
#define TERM_4 LALT(KC_4)

#define TERM_5 LALT(KC_5)
#define TERM_6 LALT(KC_6)
#define TERM_7 LALT(KC_7)
#define TERM_8 LALT(KC_8)

// Move i3 window left, right, up, and down
#define TERM_L LALT(KC_LEFT) 
#define TERM_R LALT(KC_RIGHT)
#define TERM_U LALT(KC_UP)
#define TERM_D LALT(KC_DOWN)

#define TERM_P LALT(KC_A) // Select Parent
#define TERM_C LALT(KC_Z) // Select Child

#define TERM_X LALT(KC_X) // Move space to other display vertically
#define TERM_Y LALT(LSFT(KC_X)) // Move space to other display horizontally

// Create new i3 terminal window
#define I3_TERM LALT(KC_ENT)

// Create new i3 browser window
#define I3_BROW LALT(KC_BSLS)

// Quickly jump left and right on a line (ctrl-left and ctrl-right)
#define FAST_L LCTL(KC_LEFT)
#define FAST_R LCTL(KC_RIGHT)

// Delete words left and right of cursor (ctrl-backspace and ctrl-delete)
#define WDEL_L LCTL(KC_BSPC)
#define WDEL_R LCTL(KC_DEL)

// Changes to make:
// DONE - Move Backspace to Lower key
// DONE - Move Tab back to upper left 
//  - DONE - Start using jk as escape in vim!!! 
// DONE - Move numbers to Raise Right side like a number pad
// DONE - Move Function keys to adjust layer; allow for linux term switching
// DONE - Move arrow keys to Raise and Lower
// DONE - Move special characters to match Atreus
// DONE - Add i3 New Terminal
// DONE - Add i3 New Browser
// DONE - Make BAR layer for shifting ONLY the modifiers to allow easier shortcuts
// DONE - BAR layer bound to "Both layer keys" instead of ADJUST
// DONE - Move ADJUST layer toggle to I3 layer
// - make LOWER + t do something useful
//
// Consider adding:
// Layers for "First Lower then Raise" and "First Raise then Lower"
// LED Control for different layers
//   This won't happen until I fix all the LEDs...
//   Fix the Top-facing LED so it can be used for indicating which layer
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    LT(_I3, KC_TAB),   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC ,
    KC_LCTL,           KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT ,
    LSFT_T(KC_ESC),    KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT  ,
                                                   LT(_LOWER, KC_BSPC),   KC_SPC,   LT(_RAISE, KC_SPC)
  ),
 
  [_RAISE] = LAYOUT_reviung39(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_UP,    KC_LCBR,   KC_RCBR,            KC_PGUP,  KC_7,  KC_8,  KC_9,  KC_ASTR,  KC_DEL  ,
    _______,  KC_HASH,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_MINS,            KC_PGDN,  KC_4,  KC_5,  KC_6,  KC_RBRC,  KC_BSLS ,
    _______,  KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,   KC_GRV,             KC_0,     KC_1,  KC_2,  KC_3,  KC_DOT,   KC_EQL  ,
                                                       _______,  KC_SPC,   _______
  ),
  
  [_LOWER] = LAYOUT_reviung39(
    KC_ESC,   KC_HOME,   FAST_L,  KC_UP,    FAST_R,    KC_5,               KC_VOLU, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_0,     KC_BSPC ,
    _______,  KC_END,    KC_LEFT, KC_DOWN,  KC_RGHT,   KC_BSLS,            KC_VOLD, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_F5,    KC_DEL  ,
    _______,  KC_LGUI,   KC_TAB,  KC_LALT,  KC_CAPS,   KC_QUOT,            KC_MPLY, KC_MRWD,    KC_MFFD,    WDEL_L,      WDEL_R,   _______ ,
                                                       _______,  KC_SPC,  _______
  ),
 
  // update_tri_layer_state() doesn't work if the 3rd layer is lower than the first two :(
  [_BAR] = LAYOUT_reviung39(
    KC_LALT, KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC ,
    KC_LCTL, KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT ,
    KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT  ,
                                                     _______,   KC_ESC,   _______
  ),
  
  [_I3] = LAYOUT_reviung39(
    XXXXXXX,   TERM_1,  TERM_2,   TERM_3,   TERM_4,   TERM_5,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_LSFT,   TERM_X,  TERM_U,   TERM_Y,   TERM_P,   TERM_6,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  I3_BROW,
    TERM_Y,    TERM_L,  TERM_D,   TERM_R,   TERM_C,   TERM_7,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  I3_TERM,
                                                       _______,  TG(_ADJUST),  _______
  ),

  [_ADJUST] = LAYOUT_reviung39(
    XXXXXXX,  RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,   RGB_TOG,            XXXXXXX,  KC_F9,  KC_F10, KC_F11, KC_F12,  XXXXXXX,
    XXXXXXX,  RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD,  XXXXXXX,            XXXXXXX,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   XXXXXXX,
    XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    KC_F1,  KC_F2,  KC_F3,  KC_F4,   XXXXXXX,
                                                       _______,  TO(_BASE),  _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _BAR);
}
