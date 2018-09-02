// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "timer.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _AD 3

// Custom Key names
#define TERM_1 LALT(KC_1)
#define TERM_2 LALT(KC_2)
#define TERM_3 LALT(KC_3)
#define TERM_4 LALT(KC_4)

#define TERM_5 LALT(KC_5)
#define TERM_6 LALT(KC_6)
#define TERM_7 LALT(KC_7)
#define TERM_8 LALT(KC_8)

#define SW_WIN LCTL(KC_GRV) 

void matrix_init_user(void) { // Runs boot tasks for keyboard
  _delay_us(300); // Why do we need this?
  
  // Configure the lights to be reasonable:
  //rgblight_mode(8);
  rgblight_enable();
  //rgblight_sethsv(120,255,255);
  //rgblight_mode(1);
  //rgblight_sethsv_at(0, 255, 255, 0);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_LGUI, KC_TAB,  LT(_AD, KC_BSPC), KC_LSFT,  KC_LCTL, KC_LALT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_LGUI,  KC_INS, KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_MUTE, KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_CAPS, KC_VOLD, KC_LGUI, KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS ),


  [_AD] = LAYOUT(
    TERM_1,  TERM_2,  TERM_3,   TERM_4,  TERM_5,                   KC_VOLU, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_BSPC, 
    KC_TAB,  KC_HOME, KC_UP,    KC_END,  TERM_6,                   KC_VOLD, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_DEL, 
    KC_NO,   KC_LEFT, KC_DOWN,  KC_RGHT, TERM_7,                   KC_MPLY, KC_MRWD,    KC_MFFD,    KC_NO,       KC_NO, 
    KC_NO,   KC_NO,   SW_WIN,   KC_TRNS, KC_NO,  KC_LCTL, KC_LALT, KC_NO,   KC_TRNS,    KC_NO,      KC_NO,       KC_NO)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};

uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case _RS:
      //rgblight_mode(1);
      rgblight_setrgb(100,100,100);
      //rgblight_setrgb_at(0, 0, 0, 0);
      //rgblight_setrgb_at(0, 255, 0, 1);
      break;
    case _LW:
      //rgblight_mode(1);
      //rgblight_setrgb(0, 255, 255);
      
      led[0].r = 255;
      led[0].g = 255;
      led[0].b = 0;

      led[1].r = 255;
      led[1].g = 255;
      led[1].b = 0;

      rgblight_set();
      break;
    case _AD:
      //rgblight_mode(1);
      //rgblight_setrgb_at(255, 0, 0, 2);
      //rgblight_setrgb_at(0, 255, 0, 1);

      led[0].r = 255;
      led[0].g = 0;
      led[0].b = 0;

      led[1].r = 0;
      led[1].g = 255;
      led[1].b = 0;

      rgblight_set();
      break;
    case _QW:
      rgblight_mode(8);
      rgblight_setrgb(0,0,0);
      break;
    default:
      // Default layer stuff...
      rgblight_mode(8);
      rgblight_setrgb(0,0,0);
      break;
  }
  return state;
}

void rgblight_task(void) {
  static uint16_t derp_hue = 0;
  static uint8_t last_timer = 0;

  if (timer_elapsed(last_timer) < 1) {
    return;
  }
  last_timer = timer_read();

  derp_hue += 0x1F;
  
  if (layer_state == _QW) {
    rgblight_sethsv_at(derp_hue>>8, 255, 255, 0);
    rgblight_sethsv_at((derp_hue>>8)+127,255,255,1);
  }

}
