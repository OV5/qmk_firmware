#include QMK_KEYBOARD_H

enum custom_keycodes {
    d20 = SAFE_RANGE,
	ME_ON,
	ME_OFF,
	pc1,
	pc2,
	pc3,
	pc4,
	gm,
	pc6,
};

uint32_t layer_state_set_user(uint32_t state) {
    bool numpad = !!(state & 0b110000), num_lock = IS_HOST_LED_ON(USB_LED_NUM_LOCK);
    if (num_lock != numpad) {
        tap_code(KC_NLCK);  // Toggle Num Lock to match layer state
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case d20:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/roll 1d20" SS_TAP(X_ENTER)), 15);
      }
      break;
	case ME_ON:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/talktomyself" SS_TAP(X_ENTER)), 15);
      }
      break;
	case ME_OFF:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/talktomyself off" SS_TAP(X_ENTER)), 15);
      }
      break;
	case pc1:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w brian "), 15);
      }
      break;
	case pc2:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w jed "), 15);
      }
      break;
	case pc3:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w lom "), 15);
      }
      break;
	case pc4:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w pyx "), 15);
      }
      break;
	case gm:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w gm "), 15);
      }
      break;
	case pc6:
	  if (!record->event.pressed) {
        send_string_with_delay_P(PSTR("/w urreek "), 15);
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   TO(1),   KC_F9,   _______, LCTL(LSFT(KC_C)), 
		//┌────────┬────────┬────────┬────────┐
		   _______, _______, _______, _______, 
		//┌────────┬────────┬────────┬────────┐
		   KC_VOLD, KC_MUTE, KC_VOLU, _______,
		//┌────────┬────────┬────────┬────────┐
		   KC_MPRV, KC_MPLY, KC_MNXT, _______,
		//┌────────┬────────┬────────┬────────┐
		   KC_PAUS, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT)), _______
		//└────────┴────────┴────────┴────────┘
		),

	[1] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		//┌────────┬────────┬────────┬────────┐
		   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		//┌────────┬────────┬────────┬────────┐
		   TO(4),   TO(5),   TO(6),   KC_NO,
		//┌────────┬────────┬────────┬────────┐
		   TO(0),   TO(2),   TO(3),   KC_NO,
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_NO,   KC_NO,   KC_NO
		//└────────┴────────┴────────┴────────┘
		),

	[2] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_F10,  KC_F11,  KC_F12, 
		//┌────────┬────────┬────────┬────────┐
		   KC_F7,   KC_F8,   KC_F9,   _______, 
		//┌────────┬────────┬────────┬────────┐
		   KC_F4,   KC_F5,   KC_F6,   _______,
		//┌────────┬────────┬────────┬────────┐
		   KC_F1,   KC_F2,   KC_F3,   _______,
		//┌────────┬────────┬────────┬────────┐
		   _______, _______, _______, _______
		//└────────┴────────┴────────┴────────┘
		),
	
	[3] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_PSLS, KC_NO,   KC_NO, 
		//┌────────┬────────┬────────┬────────┐
		   ME_ON,   ME_OFF,  d20,     KC_NO, 
		//┌────────┬────────┬────────┬────────┐
		   pc3,     pc4,     pc6,     KC_RCTL,
		//┌────────┬────────┬────────┬────────┐
		   gm,      pc1,     pc2,     _______,
		//┌────────┬────────┬────────┬────────┐
		   _______, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT)), _______
		//└────────┴────────┴────────┴────────┘
		),
	
	[4] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_PSLS, KC_PAST, KC_PMNS, 
		//┌────────┬────────┬────────┬────────┐
		   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, 
		//┌────────┬────────┬────────┬────────┐
		   KC_P4,   KC_P5,   KC_P6,   KC_EQL,
		//┌────────┬────────┬────────┬────────┐
		   KC_P1,   KC_P2,   KC_P3,   LT(5,KC_PENT),
		//┌────────┬────────┬────────┬────────┐
		   KC_BSPC, KC_P0,   KC_PDOT, LT(5,KC_PENT)
		//└────────┴────────┴────────┴────────┘
		),
	
	[5] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_F9,   KC_F14,  KC_F13, 
		//┌────────┬────────┬────────┬────────┐
		   KC_F18,  KC_F19, _______, _______, 
		//┌────────┬────────┬────────┬────────┐
		   KC_F15,  KC_F16,  KC_F17,  _______,
		//┌────────┬────────┬────────┬────────┐
		   KC_MPRV, KC_MPLY, KC_MNXT, _______,
		//┌────────┬────────┬────────┬────────┐
		   KC_PAUS, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT)), _______
		//└────────┴────────┴────────┴────────┘
		),

	[6] = LAYOUT_ortho_5x4(
		//┌────────┬────────┬────────┬────────┐
		   _______, KC_NO,   KC_NO,   KC_NO, 
		//┌────────┬────────┬────────┬────────┐
		   KC_F,    KC_W,    KC_K,    KC_NO, 
		//┌────────┬────────┬────────┬────────┐
		   KC_A,    KC_S,    KC_D,    KC_BTN2,
		//┌────────┬────────┬────────┬────────┐
		   KC_Q,    KC_MS_U, KC_R,   KC_BTN1,
		//┌────────┬────────┬────────┬────────┐
		   _______, _______, _______, KC_BTN1
		//└────────┴────────┴────────┴────────┘
		),
		
};
