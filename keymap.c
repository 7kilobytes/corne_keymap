#include QMK_KEYBOARD_H

#include "keymap_colemak.h"
#include "my_keycodes.h"
#include "features/layer_lock.h"

enum custom_layers {
    _QWERTY = 0,
    _COLEMAK,
    _NUM,
    _SYM,
    _NAV,
	_MS,
    _ADJUST,
};

#ifdef TAP_DANCE_ENABLE
#include "tapdances.c"
#endif

#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define SUP_GRV MT(MOD_LGUI, KC_GRV)
#define SUP_LBR MT(MOD_LGUI, KC_LBRC)
#define TAB_LCT MT(MOD_LCTL, KC_TAB)

// Layers
#define ENT_SYM LT(_SYM, KC_ENT)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define ESC_NUM LT(_NUM, KC_ESC) // ?
#define ESC_SYM LT(_SYM, KC_ESC)
#define CWT_NUM LT(_NUM, CW_TOGG)

#define NAV_F LT(_NAV, KC_F)
#define NAV_T LT(_NAV, KC_T) // colemak
#define MOS_G LT(_MS, KC_G)

// Navigation
#define CT_LEFT LCTL(KC_LEFT)
#define CT_RGHT LCTL(KC_RGHT)

// enum my_combos {
//     FG_CAPS,
//     COMBO_COUNT
// };
// 
// const uint16_t COMBO_LEN = COMBO_COUNT;
// 
// #define COMBO_KEYS(name, keycodes...) const uint16_t PROGMEM name ## _combo[] = { keycodes, COMBO_END }
// #define MAKE_COMBO(name, keycode) [name] = COMBO(name ## _combo, keycode)
// COMBO_KEYS(FG_CAPS, LT(_NAV, KC_F), LT(_MS, KC_G));
// COMBO_KEYS(FG_CAPS, KC_F, KC_G);

// combo_t key_combos[COMBO_COUNT] = {
//     MAKE_COMBO(FG_CAPS, KC_CAPS),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SUP_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  SUP_LBR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TAB_LCT,    KC_A,    KC_S,    KC_D,   NAV_F,   MOS_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, BSL_RAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CWT_NUM, SPC_LSH, ESC_SYM,   ENT_SYM, SPC_RSH, BSP_NUM
                                      //`--------------------------'  `--------------------------'
  ),

  [_COLEMAK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TAB_LCT,    KC_A,    KC_R,    KC_S,   NAV_T,   MOS_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, BSL_RAL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CWT_NUM, SPC_LSH, ESC_SYM,   ENT_SYM, SPC_RSH, BSP_NUM
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, CW_TOGG,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, _______,                      KC_MINS,    KC_4,    KC_5,    KC_6, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, _______,                       KC_DOT,    KC_1,    KC_2,    KC_3,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO,  KC_DOT,                      KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_PIPE, CM_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, CM_SCLN,                      KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,                      CT_LEFT, KC_PGDN, KC_PGUP, CT_RGHT, KC_HOME, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_ACL0, KC_BTN1, KC_BTN2, KC_BTN3,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            LLOCK, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MS] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,                      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            LLOCK, KC_BTN2, KC_BTN1,    KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_LSH:
        case SPC_RSH:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case CM_O:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
         0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  return true;
}
