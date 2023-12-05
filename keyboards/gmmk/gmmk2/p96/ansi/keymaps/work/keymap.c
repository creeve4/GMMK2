/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,
    _FL,
};




void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_mine);
}




// Custom Keycodes
enum keycodes {
	PASS = SAFE_RANGE,
};




// Tap Dance
enum tapdance_keycodes {
    MLT,
	BRI,
	FN,
	WIN,
};

// Multi
void multi (tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			tap_code(KC_HOME);
			break;
		case 2:
			tap_code16(LCTL(KC_HOME));
			break;
    }
}

// RGB Matrix
void bri (tap_dance_state_t *state, void *user_data) {
    if (rgb_matrix_get_mode() == RGB_MATRIX_CUSTOM_mine) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_off);
    } else {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_mine);
    }
}

// Function
void td_fn_finished(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		layer_on(_FL);
    } else if (state->count == 2) {
        tap_code(KC_MPLY);
    }
}

void td_fn_reset(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		layer_off(_FL);        
    }
}

// WIN
void td_win_finished(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		register_code(KC_RGUI);
    } else {
        SEND_STRING("Lovetina9"SS_TAP(X_ENT));
    }
}

void td_win_reset(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		unregister_code(KC_RGUI);        
    }
}


tap_dance_action_t tap_dance_actions[] = {
    [MLT] = ACTION_TAP_DANCE_FN(multi),
	[BRI] = ACTION_TAP_DANCE_FN(bri),
	[FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_fn_finished, td_fn_reset),
	[WIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_win_finished, td_win_reset),
};




// Combos
const uint16_t PROGMEM volume[] = {KC_VOLD, KC_VOLU, COMBO_END};

combo_t key_combos[] = {
	COMBO(volume, KC_F13),
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  TD(MLT),  TD(FN),   KC_VOLD,  KC_VOLU,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_F17,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   		  KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  			KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  TD(WIN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  TD(BRI),  _______,  KC_MPLY,  KC_MNXT,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_NUM,   _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  			 _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,                      _______,                                _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______)
};


//Caps Lock Indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(54, RGB_RED);
    }
    return false;
}
