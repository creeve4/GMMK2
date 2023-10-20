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



// Custom Keycodes
enum keycodes {
	PASS = SAFE_RANGE,
};



// Tap Dance
enum tapdance_keycodes {
    LHT,
	FN,
};

void lights (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code (KC_F13);
    } else if (state->count == 2) {
        tap_code (KC_F14);
    } else if (state->count == 3) {
        tap_code (KC_F15);
    } else {
        reset_tap_dance (state);
    }
}

void td_fn_finished(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		layer_on(_FL);
    } else {
        SEND_STRING("ChrisTina8232007"SS_TAP(X_ENT));
    }
}

void td_fn_reset(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
		layer_off(_FL);        
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [LHT] = ACTION_TAP_DANCE_FN(lights),
	[FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_fn_finished, td_fn_reset),
};



// Combos
const uint16_t PROGMEM volume[] = {KC_VOLD, KC_VOLU, COMBO_END};

combo_t key_combos[] = {
	COMBO(volume, KC_F16),
};



// RGB Ilde Timeout
static uint32_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

void refresh_rgb() {
  key_timer = timer_read32(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    is_rgb_timeout = false;
    rgb_matrix_enable_noeeprom();
  }
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {
    rgb_matrix_disable_noeeprom();
    is_rgb_timeout = true;
  }
}

// Then, call the above functions from QMK's built in post processing functions like so
/* Runs at the end of each scan loop, check if RGB timeout has occured */
void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif
}

/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
  #ifdef RGBLIGHT_TIMEOUT
  refresh_rgb();
  #endif
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  TD(LHT),  TD(FN),   KC_VOLD,  KC_VOLU,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_F17,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   		  KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  			KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  KC_RGUI,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  QK_BOOT,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  _______,  _______,  _______,  _______,   _______,  RGB_MOD,  _______,  RGB_VAD,  RGB_VAI,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  			 _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,                      KC_MPLY,                                _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______)
};


//Caps Lock Indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(54, RGB_RED);
    }
    return false;
}
