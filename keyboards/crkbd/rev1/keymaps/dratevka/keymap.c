#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_names {
  _ALPHA,
  _NUM_NAV,
  _SYMBOL,
  _MEDIA_MOUSE,
  _FUNC
};

string GUI_A = LGUI_T(KC_A);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT_split_3x6_3(
    /*╭───────────╭───────────┬───────────┬───────────┬───────────┬───────────╮   ╭───────────┬───────────┬───────────┬───────────┬───────────╮───────────╮*/
    /*│           │           │           │           │           │           │   │           │           │           │           │           │           │*/
        KC_NO,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,           KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_NO,
    /*├───────────├───────────┼───────────┼───────────┼───────────┼───────────┤   ├───────────┼───────────┼───────────┼───────────┼───────────┤───────────┤*/
    /*│           │           │           │           │           │           │   │           │           │           │           │           │           │*/
        KC_NO,      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G, KC_H,       RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_NO,
    /*├───────────├───────────┼───────────┼───────────┼───────────┼───────────┤   ├───────────┼───────────┼───────────┼───────────┼───────────┤───────────┤*/
    /*│           │           │           │           │           │           │   │           │           │           │           │           │           │*/
        KC_NO,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,           KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,
    /*╰───────────╰───────────┴───────────┼───────────┼───────────┼───────────┤   ├───────────┼───────────┼───────────┼───────────┴───────────╯───────────╯*/
    /*                                    │           │           │           │   │           │           │           │                                    */
                                            MO(3),      MO(1),      KC_LSFT,        KC_SPC,     MO(2),      MO(4)
    /*                                    ╰───────────┴───────────┤           │   │           ├───────────┴───────────╯                                    */
    /*                                                            ╰───────────╯   ╰───────────╯                                                            */
  ),

  // numbers and navigation
  [_NUM_NAV] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   /**/ KC_6,   KC_7,    KC_8,    KC_9,  KC_P0,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_EQL, /**/ KC_NO,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_NO,   KC_NO,   KC_NO,   CW_TOGG, KC_NO,  /**/ KC_NO,  KC_NO,   KC_NO,   KC_NO, KC_NO,
                      KC_NO,   KC_NO,   KC_NO,  /**/ KC_SPC, KC_TAB,  KC_BSPC
  ),

  // symbols
  [_SYMBOL] = LAYOUT_split_3x5_3(
    KC_EXLM,        KC_AT,           KC_HASH,       KC_DLR,          KC_PERC, /**/ KC_CIRC, KC_AMPR,         KC_ASTR,         KC_LPRN,         KC_RPRN,
    LGUI_T(KC_GRV), LALT_T(KC_NUBS), LCTL_T(KC_NO), LSFT_T(KC_MINS), KC_EQL,  /**/ KC_NO,   RSFT_T(KC_QUOT), RCTL_T(KC_BSLS), RALT_T(KC_LBRC), RGUI_T(KC_RBRC),
    KC_TILD,        KC_NO,           KC_NO,         KC_UNDS,         KC_PLUS, /**/ KC_NO,   KC_DQUO,         KC_PIPE,         KC_LCBR,         KC_RCBR,
                                     KC_NO,         KC_NO,           KC_NO,   /**/ KC_NO,   KC_NO,           KC_NO
  ),

  // media and mouse
  [_MEDIA_MOUSE] = LAYOUT_split_3x5_3(
    KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, /**/ KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
    KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, /**/ KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                      KC_NO,   KC_NO,   KC_NO,   /**/ KC_BTN1, KC_BTN3, KC_BTN2
  ),

  // function
  [_FUNC] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  /**/ KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_F11, /**/ KC_F12, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  /**/ KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,  /**/ KC_NO,  KC_NO,   KC_NO
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_D):
        case RCTL_T(KC_K):
        case LGUI_T(KC_A):
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 60;
        case MO(1):
        case MO(2):
            return 10;
        default:
            return TAPPING_TERM;
    }
}

enum combo_events {
  L_SPC,
  R_SPC,
  BSCP,
  ENT,
  ESC,
  TAB,
  SHRUG,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lspc_combo[] = { LCTL_T(KC_D),  LSFT_T(KC_F), COMBO_END };
const uint16_t PROGMEM rspc_combo[] = { RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END };
const uint16_t PROGMEM bspc_combo[] = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM ent_combo[] = { RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END };
const uint16_t PROGMEM esc_combo[] = { KC_E, KC_R, COMBO_END };
const uint16_t PROGMEM tab_combo[] = { LCTL_T(KC_D),  LSFT_T(KC_F), COMBO_END };

const uint16_t PROGMEM shrg_combo[] = {LALT_T(KC_S), KC_G, COMBO_END};

combo_t key_combos[] = {
    [L_SPC] = COMBO(lspc_combo, KC_SPC),
    [R_SPC] = COMBO(rspc_combo, KC_SPC),
    [BSCP] = COMBO(bspc_combo, KC_BSPC),
    [ENT] = COMBO(ent_combo, KC_ENT),
    [ESC] = COMBO(esc_combo, KC_ESC),
    [TAB] = COMBO(tab_combo, KC_TAB),
    [SHRUG] = COMBO_ACTION(shrg_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SHRUG:
      if (pressed) {
        send_unicode_string("combo test");
      }
      break;
  }
}

#ifdef OLED_ENABLE


bool render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _ALPHA:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _NUM_NAV:
            oled_write_ln_P(PSTR("NUMNAV"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("SYMBOL"), false);
            break;
        case _MEDIA_MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}

static void render_logo(void) {
    oled_write_P(PSTR("¯\\_(ツ)_/¯"), false);
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}
#endif