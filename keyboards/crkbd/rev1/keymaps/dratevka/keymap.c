#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // alpha
  [0] = LAYOUT_split_3x5_3(
    KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,              /**/ KC_Y,   KC_U,          KC_I,         KC_O,         KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,              /**/ KC_H,   RSFT_T(KC_J),  RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_Z,         KC_X,         KC_C,          KC_V,          KC_B,              /**/ KC_N,   KC_M,          KC_COMM,      KC_DOT,       KC_QUOT,
                                LT(4, KC_ESC), LT(1, KC_TAB), LT(3, KC_ENT),     /**/ KC_SPC, LT(2, KC_DEL), KC_BSPC
  ),

  // numbers + navigation
  [1] = LAYOUT_split_3x5_3(
    KC_1,            KC_2,            KC_3,             KC_4,            KC_5,   /**/ KC_6,   KC_7,    KC_8,    KC_9,  KC_P0,
    LGUI_T(KC_PLUS), LALT_T(KC_MINS), LCTL_T(KC_ASTR),  LSFT_T(KC_SLSH), KC_EQL, /**/ KC_NO,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_NO,           KC_NO,           KC_NO,            CW_TOGG,         KC_NO,  /**/ KC_NO,  KC_NO,   KC_NO,   KC_NO, KC_NO,
                                      KC_NO,            KC_NO,           KC_NO,  /**/ KC_SPC, KC_DEL,  KC_BSPC
  ),

  // symbols
  [2] = LAYOUT_split_3x5_3(
    KC_EXLM,        KC_AT,           KC_HASH,       KC_DLR,          KC_PERC,      /**/ KC_CIRC, KC_AMPR,         KC_ASTR,         KC_LPRN,         KC_RPRN,
    LGUI_T(KC_GRV), LALT_T(KC_NUBS), LCTL_T(KC_NO), LSFT_T(KC_MINS), KC_EQL,       /**/ KC_NO,   RSFT_T(KC_SLSH), RCTL_T(KC_BSLS), LALT_T(KC_LBRC), RGUI_T(KC_RBRC),
    KC_TILD,        KC_NO,           KC_NO,         KC_UNDS,         KC_PLUS,      /**/ KC_NO,   KC_QUES,         KC_PIPE,         KC_LCBR,         KC_RCBR,
                                     KC_NO,         KC_NO,           KC_NO,        /**/ KC_NO,   KC_NO,           KC_NO
  ),

  // media + mouse
  [3] = LAYOUT_split_3x5_3(
    KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, /**/ KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
    KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, /**/ KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                      KC_NO,   KC_NO,   KC_NO,   /**/ KC_BTN1, KC_BTN2, KC_BTN3
  ),

  // function
  [4] = LAYOUT_split_3x5_3(
    KC_F1,         KC_F2,         KC_F3,         KC_F4,          KC_F5,          /**/ KC_F6,  KC_F7,         KC_F8,         KC_F9,         KC_F10,
    LGUI_T(KC_NO), LALT_T(KC_NO), LCTL_T(KC_NO), LSFT_T(KC_NO),  KC_F11,         /**/ KC_F12, RSFT_T(KC_NO), RCTL_T(KC_NO), LALT_T(KC_NO), RGUI_T(KC_NO),
    KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_NO,          /**/ KC_NO,  KC_NO,         KC_NO,         KC_NO,         KC_NO,
                                  KC_NO,         KC_NO,          KC_NO,          /**/ KC_NO,  KC_NO,         KC_NO
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_D):
        case RCTL_T(KC_K):
        case LGUI_T(KC_A):
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 60;
        default:
            return TAPPING_TERM;
    }
}