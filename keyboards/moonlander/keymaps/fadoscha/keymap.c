#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,       // default layer
    NEO,       // symbols
    TRIPPLE,    // cmd + ctrl + alt
};

enum custom_keycodes {
    MA_0 = ML_SAFE_RANGE,
    MA_1
};

#define FA_SPC LCAG_T(KC_SPC)
#define FA_BSPC LCTL_T(KC_BSPC)
#define FA_ENT LCMD_T(KC_ENT)
#define FA_TAB LCMD_T(KC_TAB)

#define FA_Z LSFT_T(KC_Z)
#define FA_X LT(NEO, KC_X)

#define FA_DOT LT(NEO, KC_DOT)
#define FA_SLSH RSFT_T(KC_SLSH)

#define FA_DEC LGUI(KC_MINUS)
#define FA_INC LGUI(KC_EQUAL)

#define FA_NOM HYPR(KC_F3)
#define FA_MAG HYPR(KC_F4)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    FA_NOM,            FA_MAG,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    FA_DEC,            FA_INC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FA_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MA_0,              MA_1,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, FA_Z,    FA_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, FA_DOT,  FA_SLSH, KC_RSFT,
        KC_GRV,  QK_BOOT, KC_LCTL, KC_LOPT, KC_LCMD,          KC_ESC,            QK_BOOT,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                                            FA_TAB,  FA_SPC,  KC_ENT,            KC_LALT,  FA_ENT,  KC_ESC
    ),

    [NEO] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_ASTR, KC_AMPR, KC_TILD, _______,           _______, _______, _______, KC_LPRN, KC_RPRN, KC_PLUS, _______, _______, KC_CIRC, KC_TILD, KC_HASH, KC_DLR,  KC_PERC, _______,           _______, KC_MINS, KC_RCBR, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,
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
        case MA_0:
            SEND_STRING("[ ] ");
            break;
        case MA_1:
            SEND_STRING("^lrx" SS_DELAY(100) SS_TAP(X_ESCAPE));
            break;
        }
    }
    return true;
}
