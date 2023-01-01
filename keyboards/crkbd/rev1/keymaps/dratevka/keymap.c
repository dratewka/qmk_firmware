/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
    KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,              /**/ KC_Y,   KC_U,          KC_I,         KC_O,         KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,              /**/ KC_H,   RSFT_T(KC_J),  RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_Z,         KC_X,         KC_C,          KC_V,          KC_B,              /**/ KC_N,   KC_M,          KC_COMM,      KC_DOT,       KC_QUOT,
                                LT(4, KC_ESC), LT(1, KC_TAB), LT(3, KC_ENT),     /**/ KC_SPC, LT(2, KC_DEL), KC_BSPC
  ),

  [1] = LAYOUT_split_3x5_3(
    KC_1,            KC_2,            KC_3,             KC_4,            KC_5,   /**/ KC_6,  KC_7,          KC_8,    KC_9,  KC_P0,
    LGUI_T(KC_PLUS), LALT_T(KC_MINS), LCTL_T(KC_ASTR),  LSFT_T(KC_SLSH), KC_EQL, /**/ KC_NO, KC_LEFT,       KC_DOWN, KC_UP, KC_RGHT,
    KC_NO,           KC_NO,           KC_NO,            KC_NO,           KC_NO,  /**/ KC_NO, KC_M,          KC_NO,   KC_NO, KC_NO,
                                      KC_NO,            KC_NO,           KC_NO,  /**/ KC_NO, KC_NO,         KC_NO
  ),

  [2] = LAYOUT_split_3x5_3(
    KC_EXLM,        KC_AT,         KC_HASH,       KC_DLR,          KC_PERC,      /**/ KC_CIRC, KC_AMPR,         KC_ASTR,         KC_LPRN,         KC_RPRN,
    LGUI_T(KC_GRV), LALT_T(KC_NO), LCTL_T(KC_NO), LSFT_T(KC_MINS), KC_EQL,       /**/ KC_NO,   RSFT_T(KC_SLSH), RCTL_T(KC_BSLS), RALT_T(KC_LBRC), RGUI_T(KC_RBRC),
    KC_TILD,        KC_NO,         KC_NO,         KC_UNDS,         KC_PLUS,      /**/ KC_NO,   KC_QUES,         KC_PIPE,         KC_LCBR,         KC_RCBR,
                                   KC_NO,         KC_NO,           KC_NO,        /**/ KC_NO,   KC_NO,           KC_NO
  ),

  [3] = LAYOUT_split_3x5_3(
    KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, /**/ KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
    KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, /**/ KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                      KC_NO,   KC_NO,   KC_NO,   /**/ KC_BTN1, KC_BTN2, KC_BTN3
  )

  [4] = LAYOUT_split_3x5_3(
    KC_F1,         KC_F2,         KC_F3,         KC_F4,          KC_F5,          /**/ KC_F6,  KC_F7,         KC_F8,         KC_F9,         KC_10,
    LGUI_T(KC_NO), LALT_T(KC_NO), LCTL_T(KC_NO), LSFT_T(KC_NO),  KC_F11,         /**/ KC_F12, RSFT_T(KC_NO), RCTL_T(KC_NO), RALT_T(KC_NO), RGUI_T(KC_NO),
    KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_NO,          /**/ KC_NO,  KC_NO,         KC_NO,         KC_NO,         KC_NO,
                                  KC_NO,         KC_NO,          KC_NO,          /**/ KC_NO,  KC_NO,         KC_NO
  )
};