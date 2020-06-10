#include QMK_KEYBOARD_H

#define FN_ENT LT(L_FN, KC_ENT)
#define ARW_SPC LT(L_ARROW,KC_SPC)
#define WIN_OFF MAGIC_NO_GUI
#define WIN_ON MAGIC_UNNO_GUI
#define Esc_F4 TD(TD_Esc_AltF4)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define ALL LCTL(KC_A)

enum layers {
    L_QWERTY,
    L_COLEMAK,
    L_FN,
    L_ARROW,
    L_MATH
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    frac,
    matrix,
    align,
    textbf,
    noindent,
    alpha,
    beta,
    lambda,
    root,
    implies
};

uint32_t layer_state_set_user(uint32_t state) {
    bool numpad = !!(state & 0b10000), num_lock = IS_HOST_LED_ON(USB_LED_NUM_LOCK);
    if (num_lock != numpad) {
        tap_code(KC_NLCK);  // Toggle Num Lock to match layer state
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
          print("mode just switched to qwerty and this is a huge string\n");
          set_single_persistent_default_layer(L_QWERTY);
        }
        return false;

    case COLEMAK:
        if (record->event.pressed) {
          set_single_persistent_default_layer(L_COLEMAK);
        }
        return false;
    
    case frac:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\frac{}{}\n"), 20);
      }
      break;
    case matrix:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\begin{bmatrix}\n"), 20);
      }
      break;
    case align:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\begin{align*}\n"), 20);
      }
      break;
    case textbf:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\textbf{}\n"), 20);
      }
      break;
    case noindent:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\noindent\\textbf{}\n"), 20);
      }
      break;
    case alpha:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\alpha\n"), 20);
      }
      break;
    case beta:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\beta\n"), 20);
      }
      break;
    case lambda:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\lambda\n"), 20);
      }
      break;
    case root:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\sqrt{}\n"), 20);
      }
      break;
    case implies:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("\\implies "), 20);
      }
      break;
    }
    return true;
};

enum tap_dance {
    TD_Esc_AltF4,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Esc_AltF4] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWERTY] = LAYOUT_all(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSLS,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, LT(L_FN,KC_DEL),
        KC_NO, KC_NO, KC_LALT, KC_SPC, KC_RCTL, ARW_SPC, LALT(KC_TAB), RCTL_T(KC_PAUS), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [L_COLEMAK] = LAYOUT_all(
        Esc_F4,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSLS,
        KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
        KC_LSPO, KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP, LT(L_FN,KC_DEL),
        MO(L_MATH), KC_LGUI, KC_LALT, ARW_SPC, FN_ENT, KC_BSPC, LALT(KC_TAB), RCTL_T(KC_PAUS), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [L_FN] = LAYOUT_all(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,  KC_F12,  _______, RESET,
        _______, RGB_HUD, RGB_HUI, RGB_TOG, RGB_SAD, RGB_SAI, RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, _______, _______, KC_DEL,
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COLEMAK, QWERTY, _______,
        _______, WIN_OFF, WIN_ON, _______, _______, _______, _______, _______, _______, _______, LCTL(LSFT(KC_C))
    ),
    [L_ARROW] = LAYOUT_all(
        _______, frac, matrix, root, align, textbf, noindent, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, KC_BSLS, _______,
        KC_CAPS, alpha, beta, KC_MINS, KC_EQL, KC_GRV, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
        _______, _______, lambda, implies, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, COPY, PASTE, ALL
    ),
    [L_MATH] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_0, KC_MINS, KC_EQL,  KC_GRV, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB, KC_P0, KC_DOT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
