#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | ` ~    |   Q  |   D  |   R  |   W  |   B  | Tab  |           |Enter |   J  |   F  |   U  |   P  |   ;  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | PgUp   |   A  |   S  |H/Shft|T/Ctrl|   G  |------|           |------|   Y  |N/Ctrl|E/Shft|   O  |I / L2|' / Cmd |
   * |--------+------+------+------+------+------| Esc  |           | SLCK |------+------+------+------+------+--------|
   * | PgDwn  |Z/Ctrl|   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| LAlt | LGui |                                       | RGui | RAlt |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Left |       |  Up  |        |      |
   *                                 |Backsp| L1   |------|       |------|   L1   |Space |
   *                                 |ace   |      |Right |       | Down |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox(  // layer 0 : default
                          // left hand
                          KC_EQL,        KC_1,        KC_2,     KC_3,          KC_4,        KC_5,    KC_LEFT,
                          KC_GRV,        KC_Q,        KC_D,     KC_R,          KC_W,        KC_B,    KC_TAB,
                          KC_PGUP,       KC_A,        KC_S,     SFT_T(KC_H),   CTL_T(KC_T), KC_G,
                          KC_PGDN,       CTL_T(KC_Z), KC_X,     KC_M,          KC_C,        KC_V,    KC_ESC,
                          LT(SYMB,       KC_GRV),     KC_QUOT,  LALT(KC_LSFT), KC_LALT,     KC_LGUI,
                          ALT_T(KC_APP), KC_LGUI,
                          KC_LEFT,
                          KC_BSPC,       MO(SYMB),    KC_RIGHT,
                          // right hand
                          KC_RGHT,      KC_6,          KC_7,         KC_8,    KC_9,    KC_0,           KC_MINS,
                          KC_ENT,       KC_J,          KC_F,         KC_U,    KC_P,    KC_SCLN,        KC_BSLS,
                          KC_Y,         RCTL_T(KC_N),  RSFT_T(KC_E), KC_O,    LT(MDIA, KC_I),          GUI_T(KC_QUOT),
                          KC_SLCK,      KC_K,          KC_L,         KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_RSFT,
                          KC_RGUI,      KC_RALT,       KC_LBRC,      KC_RBRC, KC_FN1,
                          KC_LALT,      CTL_T(KC_ESC),
                          KC_UP,
                          KC_DOWN,      MO(SYMB),      KC_SPC
  ),
  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      | PgUp |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|PgDown|   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   <  |   >  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | EPRM |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Animat|      |       |Toggle|Solid |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
   *                                 |ness- |ness+ |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = LAYOUT_ergodox(
                          // left hand
                          VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
                          KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
                          KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
                          KC_TRNS,KC_PERC,KC_CIRC,KC_LT,KC_GT,KC_TILD,KC_TRNS,
                          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                          RGB_MOD,KC_TRNS,
                          KC_TRNS,
                          RGB_VAD,RGB_VAI,KC_TRNS,
                          // right hand
                          KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
                          KC_TRNS, KC_PGUP, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                          KC_PGDN, KC_4,    KC_5,   KC_6,    KC_PLUS, KC_TRNS,
                          KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_TRNS, KC_DOT,  KC_0,   KC_EQL,  KC_TRNS,
                          RGB_TOG, RGB_SLD,
                          KC_TRNS,
                          KC_TRNS, RGB_HUD, RGB_HUI
                          ),
  /* Keymap 2: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down |Right |      |  Play  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      | Prev | Next |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |Brwser|
   *                                 |      |      |------|       |------|      |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [MDIA] = LAYOUT_ergodox(
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                          KC_TRNS, KC_TRNS,
                          KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS,
                          // right hand
                          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_MPLY,
                          KC_TRNS,  KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS,
                          KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_WBAK
                          ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  default:
    // none
    break;
  }

};
