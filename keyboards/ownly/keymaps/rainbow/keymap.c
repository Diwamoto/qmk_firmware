#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define XXXXXX   KC_NO
#define KC_RST   RESET
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.           ,--------------------------------------------------------.
 * |  ESC  |   1   |   2   |   3   |   4   |   5   |           |   6   |   7   |   8   |   9   |   0   |  BSPC  |  art..|
 * |---------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+--------+-------|
 * |  Tab   |   Q   |   W   |   E   |   R   |   T   |           |   Y   |   U   |   I   |   O   |   P   |   @   |
 * |----------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
 * |   Caps  |   A   |   S   |   D   |   F   |   G   |          |   H   |   J   |   K   |   L   |   ;   |   :   |
 * |------------+-------+-------+-------+-------+-------|      |-------+-------+-------+-------+-------+-------|
 * |   LShift  |   Z   |   X   |   C   |   V   |   B   |          |   N   |   M   |   ,   |   .   |   /   |RShift|
 * `------------------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------'
 * |  LCTRL |          | LALT |      |LOWER |    Space   |   \  Enter   | RAISE |      | RALT |  RGUI  | RCTRL |
 * |       |          |      |      |      |            |     \        |       |      |      |        |       |
 * `------'          `-------       ------+-------------'     '-------+--------'     '------+--------+-------'
 */

 [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   KC_RO,\
  //|--------+--------+--------+--------+--------+----------------|     |------------+------+-------------+--------+--------+--------|
      KC_LCTRL,        KC_LALT,              LOWER,         KC_SPC,       KC_ENT,       RAISE,              KC_RALT, KC_RGUI, KC_RCTL\
  ///-------------------------------------------------------------'     `--------------------'
    ),
/* LOWER
 * ,------------------------------------------------.        ,----------------------------------------------.
 * |  半／全  |  F1   |  F2   |  F3   |  F4   |  F5   |        |  F6   |  F7   |  F8   |  F9   |  F10  | BSPC |
 * |---------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+------|
 * |  Tab   |   1   |   2   |   3   |   4   |   5   |        |   6   |   7   |   8   |   9   |   0   |   @   |
 * |----------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------|
 * | CapsLock|   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   :   |   '   |
 * |------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------|
 * |   LShift  |   Z   |   X   |   C   |   V   |   B   |        |      |   ¥   |   ,   |   .   |     |RShift|
 * `------------------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------'
 * |  LCTRL |          | LALT |      |LOWER |    Space   |   \  Enter   | RAISE |      | RALT |  RGUI  | RCTRL |
 * |       |          |      |      |      |            |     \        |       |      |      |        |       |
 * `------'          `-------       ------+-------------'     '-------+--------'     '------+--------+-------'
 */
[_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_MINS, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_EQL, KC_INT3, KC_COMM,  KC_DOT,  KC_UP,  KC_BSLS,\
  //|--------+--------+--------+--------+--------+----------------|     |------------+------+-------------+--------+--------+--------|
      KC_LCTL,        KC_LALT,              LOWER,         KC_SPC,       KC_BSPC,       RAISE,               KC_LEFT, KC_DOWN, KC_RIGHT\
  ///-------------------------------------------------------------'     `--------------------'
),
/* RAISE
 * ,------------------------------------------------.        ,----------------------------------------------.
 * |  ESC  |  XXXX |  XXXX |  XXXX |   4   |   5   |        |   6   |   7   |   8   |   9   |   0   | DEL  |
 * |---------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+------|
 * |  Tab   |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |   @   |
 * |----------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------|
 * |  LCTRL  |   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------|
 * |   LShift  |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   |RShift|
 * `------------------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------'
 * |  LCTRL |          | LGUI |      |LOWER |    Space   |   \  Enter   | RAISE |      | RALT |  RGUI  | RCTRL |
 * |       |          |      |      |      |            |     \        |       |      |      |        |       |
 * `------'          `-------       ------+-------------'     '-------+--------'     '------+--------+-------'
 */


[_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_EXLM, S(KC_2), KC_HASH,  KC_DLR, KC_PERC,                      S(KC_6), S(KC_7), KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J, KC_RCBR, KC_PIPE, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   S(KC_INT3), KC_PLUS, KC_RBRC, KC_BSLS, KC_QUES,S(KC_INT1),\
  //|--------+--------+--------+--------+--------+----------------|     |------------+------+-------------+--------+--------+--------|
      KC_LCTL,        KC_LCTRL,              LOWER,         KC_SPC,       KC_ENT,       RAISE,             KC_RALT, KC_RGUI, KC_RCTL\
  ///-------------------------------------------------------------'     `--------------------'
),
/* ADJUST
 * ,------------------------------------------------.        ,----------------------------------------------.
 * |  RST  |       |       |       |       |       |        |       |       |       |       |       | 消灯 |
 * |---------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+------|
 * |        |       |       |       |       |       |        |       |       |       |       |       |       |
 * |----------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------|
 * |         |       |       | 色彩↓|       | 切替  |        |       |       | 色彩↑|       |       |       |
 * |------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------|
 * |           |       |       | 電卓  |       |       |        |       |       |       |       |輝度↑ |       |
 * `------------------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------'
 * |        |          |      |      |LOWER |            |   \          | RAISE |      |彩度↓| 輝度↓ | 彩度↑|
 * |       |          |      |      |      |            |     \        |       |      |      |        |       |
 * `------'          `-------       ------+-------------'     '-------+--------'     '------+--------+-------'
 */
  [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_RST,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,                       XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, KC_LTOG,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, KC_LHUD,                       XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXX,  XXXXXX,  XXXXXX, KC_LHUD,  XXXXXX, KC_LMOD,                       XXXXXX,  XXXXXX, KC_LHUI,  XXXXXX,  XXXXXX,  XXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXX,  XXXXXX,  XXXXXX, KC_CALC,  XXXXXX,  XXXXXX,                       XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, KC_LVAI,  XXXXXX,\
  //|--------+--------+--------+--------+--------+----------------|     |------------+------+-------------+--------+--------+--------|
      XXXXXX,        XXXXXX,              LOWER,         XXXXXX,       XXXXXX,       RAISE,                KC_LSAD, KC_LVAD,  KC_LSAI\
  ///-------------------------------------------------------------'     `--------------------'
)
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
  //enable rainbow led animation
  rgblight_step();
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  #ifdef MASTER_RIGHT
    if (is_keyboard_master())
        return rotation;
      else
        return OLED_ROTATION_180;
  #else
      if (is_keyboard_master())
        return OLED_ROTATION_180;
      else
        return rotation;
  #endif
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set_keylog(keycode, record);
#endif
    // set_timelog();
  }
    switch (keycode) {
    case LOWER:
      if (record->event.pressed) {

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
