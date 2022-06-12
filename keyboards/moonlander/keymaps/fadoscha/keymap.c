/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

enum layers {
    BASE,       // default layer
    NEO,       // symbols
    TRIPPLE,    // cmd + ctrl + alt
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

#define FA_SPC LCAG_T(KC_SPC)
#define FA_BSPC LCTL_T(KC_BSPC)
#define FA_ENT LCMD_T(KC_ENT)

#define FA_Z LSFT_T(KC_Z)
#define FA_X LT(NEO, KC_X)

#define FA_DOT LT(NEO, KC_DOT)
#define FA_SLSH RSFT_T(KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FA_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, FA_Z,    FA_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, FA_DOT,  FA_SLSH, KC_RSFT,
        KC_GRV,  QK_BOOT, KC_LCTL, KC_LOPT, KC_LCMD,          QK_BOOT,           CAPSWRD,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                                            KC_TAB,  FA_SPC,  KC_LGUI,           KC_LALT,  FA_ENT,  KC_ESC
    ),

    [NEO] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_ASTR, KC_AMPR, KC_TILD, _______,           _______, _______, _______, KC_LPRN, KC_RPRN, KC_PLUS, _______,
        _______, KC_CIRC, KC_TILD, KC_HASH, KC_DLR,  KC_PERC, _______,           _______, KC_MINS, KC_RCBR, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,
        _______, KC_GRV,  KC_BSLS, KC_SLSH, KC_PIPE, _______,                             _______, KC_ASTR, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [TRIPPLE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};


void keyboard_post_init_user(void) {
  rgb_matrix_disable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
