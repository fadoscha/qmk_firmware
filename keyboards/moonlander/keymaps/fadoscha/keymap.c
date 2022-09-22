#include QMK_KEYBOARD_H
#include "version.h"
#include "raw_hid.h"

// Left Half
#define FA_QUIT LGUI(KC_Q)
#define FA_NTAB LGUI(KC_T)
#define FA_CLS LGUI(KC_W)

#define FA_BSPC LCTL_T(KC_BSPC)
#define FA_Z LSFT_T(KC_Z)
#define FA_X LT(NEO, KC_X)

#define FA_C C_S_T(KC_C)
#define FA_V LT(VIM, KC_V)

#define FA_GRV LOPT_T(KC_GRV)
#define FA_RVL LGUI(KC_0)

// Right Half
#define FA_QUOT RCTL_T(KC_QUOT)
#define FA_DOT LT(NEO, KC_DOT)
#define FA_SLSH RSFT_T(KC_SLSH)

#define FA_UNDS ROPT_T(KC_F17)
#define FA_FCS LGUI(LSFT(KC_X))             // Focus Xcode      |       cmd + shift + x

// Inrease Decrease
#define FA_DEC LGUI(KC_MINUS)               // Decrease size    |       cmd + -
#define FA_INC LGUI(KC_EQUAL)               // Increase size    |       cmd + =

// Umlaute
#define FA_UE LOPT(KC_U)
#define FA_SS LOPT(KC_S)

// Copy Paste
#define FA_CPY LGUI(KC_C)
#define FA_PST LGUI(KC_V)
#define FA_CUT LGUI(KC_X)

#define FA_GOOGLE HYPR(KC_F1)

#define F_NXT LSA(KC_N)
#define M_NXT MEH(KC_N)

// Thumb Cluster Left
#define FA_TAB LCMD_T(KC_TAB)               // Tab              |        cmd
#define MOD_1  LSA_T(KC_SPC)                // Amethyst mod1    |        option + shift
#define MOD_2  MEH_T(KC_F18)                // Amethyst mod2    |        ctrl + option + shift

#define FA_RUN LGUI(KC_R)                   // Xcode Run        |        cmd + r

// Thumb Cluster Right
#define FA_ESC LSG_T(KC_ESC)                // ESC              |        cmd + shift
#define FA_ENT HYPR_T(KC_ENT)               // Enter            |        hyper
#define FA_PLT LAG_T(KC_F19)                // cmd + shift + p

#define FA_GRM RGUI_T(KC_F20)               // Grammar
#define STR_E LCTL(KC_E)
#define STR_Y LCTL(KC_Y)

#define CK_F1 LCMD(KC_F1)
#define CK_F2 LCMD(KC_F2)
#define CK_F3 LCMD(KC_F3)
#define CK_F4 LCMD(KC_F4)
#define CK_F5 LCMD(KC_F5)
#define CK_F6 LCMD(KC_F6)
#define CK_F7 LCMD(KC_F7)
#define CK_F8 LCMD(KC_F8)
#define CK_F9 LCMD(KC_F9)
#define CK_F10 LCMD(KC_F10)
#define CK_F11 LCMD(KC_F11)
#define CK_F12 LCMD(KC_F12)
#define CK_F13 LCMD(KC_F13)
#define CK_F14 LCMD(KC_F14)
#define CK_F15 LCMD(KC_F15)

enum layers {
    BASE,           // Default Layer
    NEO,            // Symbols
    VIM,            // Vim
    FUN,            // Function Keys
};

enum custom_keycodes {
    MA_0 = ML_SAFE_RANGE,
    MA_1,
    MA_2,
    MA_3,
    MA_4,
    MA_5,
    Vi_gg,
    Vi_G,
    Vi_s,
    Vi_g_,
    Vi_ciw,
};

uint8_t rgb_index = 0x00;
RGB rgb_value = {
    .r = 0x00,
    .g = 0x00,
    .b = 0x00,
};

uint8_t caps_word_rgb_index = 31;
RGB caps_word_rgb_value = {
    .r = 0x00,
    .g = 0x00,
    .b = 0x00,
};

// MARK: - Combos

const uint16_t PROGMEM combo_middle_piano_keys[] = {LSA_T(KC_SPC), HYPR_T(KC_ENT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_middle_piano_keys, LGUI(KC_SPC)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        FA_QUIT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    FA_NTAB,           FA_INC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        FA_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    FA_GOOGLE,         FA_DEC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        FA_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    CAPSWRD,           Vi_ciw,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, FA_QUOT,
        OSL(FUN),FA_Z,    FA_X,    KC_C,    FA_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, FA_DOT,  FA_SLSH, FA_UNDS,
        F_NXT,   M_NXT,   KC_LCTL, KC_LOPT, KC_LCMD,          FA_RUN,            FA_GRM,           KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,
                                            FA_TAB,  MOD_1,   MOD_2,             FA_PLT,  FA_ENT,  FA_ESC
    ),

    [NEO] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, MA_3,
        _______, KC_EXLM, KC_AT,   KC_ASTR, KC_CIRC, KC_TILD, _______,           _______, MA_3,    FA_UE,   KC_LPRN, KC_RPRN, KC_PERC, KC_EQL,
        _______, KC_AMPR, FA_SS,   KC_DLR,  KC_EXLM, KC_ASTR, _______,           _______, KC_HASH, KC_LCBR, KC_RCBR, KC_RBRC, KC_PLUS, KC_EQL,
        _______, MA_1,    MA_0,    FA_CPY,  FA_PST,  KC_PIPE,                             MA_2,    MA_4,    KC_LBRC, KC_RBRC, KC_PIPE, KC_PIPE,
        _______, _______, _______, _______, _______,          QK_BOOT,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [VIM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, KC_CIRC,   _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_B,    STR_E,   STR_Y,   KC_W,    _______, Vi_s,
        _______, _______, _______, _______, _______, _______,                             Vi_g_,   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [FUN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, CK_F1,   CK_F2,   CK_F3,   CK_F4,   CK_F5,   _______,           _______, CK_F1,   CK_F2,   CK_F3,   CK_F4,   CK_F5,   _______,
        _______, CK_F6,   CK_F7,   CK_F8,   CK_F9,   CK_F10,  _______,           _______, CK_F6,   CK_F7,   CK_F8,   CK_F9,   CK_F10,  _______,
        _______, CK_F11,  CK_F12,  CK_F13,  CK_F14,  CK_F15,                              CK_F11,  CK_F12,  CK_F13,  CK_F14,  CK_F15,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

// MARK: - Layer Handling
layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_WHITE},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_RED},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {HSV_GOLD}, {0,0,0},

        {HSV_BLUE}, {HSV_WHITE}, {HSV_BLUE},
        {HSV_RED},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_PURPLE},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_BLUE},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_RED},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_TURQUOISE},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {HSV_YELLOW},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},

        {HSV_GREEN}, {HSV_WHITE}, {HSV_GREEN},
        {HSV_RED},
    },
    [1] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {HSV_TURQUOISE}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0},

        {HSV_BLUE}, {HSV_WHITE}, {HSV_BLUE},
        {HSV_RED},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {HSV_BLUE}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {HSV_GREEN},
        {0,0,0}, {0,0,0}, {0,0,0},

        {HSV_GREEN}, {HSV_WHITE}, {HSV_GREEN},
        {HSV_RED},
    },
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} }
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(0);
      break;
    case 2:
      set_layer_color(0);
      break;
    case 3:
      set_layer_color(1);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }

  rgb_matrix_set_color(rgb_index, rgb_value.r, rgb_value.g, rgb_value.b);
  rgb_matrix_set_color(caps_word_rgb_index, caps_word_rgb_value.r, caps_word_rgb_value.g, caps_word_rgb_value.b);
}

void set_lightning_value(uint8_t *data) {
    uint8_t *data_value = &(data[0]);

    rgb_index = data_value[0];

    RGB rgb = {
        .r = data_value[1],
        .g = data_value[2],
        .b = data_value[3]
    };
    rgb_value = rgb; // rgb_matrix_sethsv_noeeprom(value_data[0], value_data[1], rgblight_get_val())
};

// MARK: - Caps Word

void caps_word_set_user(bool active) {
    if (active) {
        RGB rgb = {
            .r = 0xFF,
            .g = 0x00,
            .b = 0x00
        };
        caps_word_rgb_value = rgb;
    } else {
        RGB rgb = {
            .r = 0x00,
            .g = 0x00,
            .b = 0x00
        };
        caps_word_rgb_value = rgb;
    }
}

// special key handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (record->event.pressed) {
        switch (keycode) {
        case MA_0:
            SEND_STRING("- [ ] ");
            break;
        case MA_1:
            SEND_STRING("^f[lrx" SS_DELAY(100) SS_TAP(X_ESCAPE));
            break;
        case MA_2:
            SEND_STRING("->");
            break;
        case MA_3:
            SEND_STRING("\\()" SS_DELAY(200) SS_TAP(X_LEFT));
            break;
        case MA_4:
            SEND_STRING("// MARK: - ");
            break;
        case MA_5:
            SEND_STRING("^f[lrx" SS_DELAY(100) SS_TAP(X_ESCAPE) "dd" SS_DELAY(100) "}}" SS_DELAY(100) "P" SS_DELAY(100) "{{");
            break;
        case Vi_gg:
            SEND_STRING("gg");
            break;
        case Vi_G:
            SEND_STRING("G");
            break;
        case Vi_s:
            SEND_STRING("vi\"");
            break;
        case Vi_g_:
            SEND_STRING("g_");
            break;
        case Vi_ciw:
            SEND_STRING("ciw");
            break;
        }
    }
    return true;
}

// MARK: - Raw HID

enum hid_command {
    lighting_get_value       = 0x01,
    lighting_set_value       = 0x02,
    lighting_toggle_value    = 0x03,
};

void raw_hid_receive(uint8_t *data, uint8_t length) {

    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);

    switch (*command_id) {
        case lighting_get_value:
            // via_qmk_rgblight_set_value(command_data);
            break;
        case lighting_set_value:
            set_lightning_value(command_data);
            break;
        case lighting_toggle_value:
            // eeconfig_update_rgb_matrix();
            break;
        default:
            break;
    }

    raw_hid_send(data, length);
};
