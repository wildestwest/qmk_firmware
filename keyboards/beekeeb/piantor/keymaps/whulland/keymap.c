// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAVIGATION,
    _SYMBOLS,
    _WORKSPACES,
    _NUMBERS,
    _MOUSE,
    _UNICODE,
};

enum unicode_names {
    THUMB_UP,   // 👍
    SMILE,      // 😄
    ROFL,       // 🤣
    FROWN,      // 🙁
    THUMB_DN,   // 👎
    PRAY,       // 🙏
    PARTY,      // 🎉
    ROCKET,     // 🚀
    HEART,      // ❤
    FIRE,       // 🔥
    EYES,       // 👀
    THINK,      // 🤔
    BUG,        // 🐛
    CHECK,      // ✅
    CROSS,      // ❌
    HUNDRED,    // 💯
    SCREAM,     // 😱
    SHRUG,      // 🤷
};

const uint32_t unicode_map[] PROGMEM = {
    [THUMB_UP] = 0x1F44D,
    [SMILE]    = 0x1F604,
    [ROFL]     = 0x1F923,
    [FROWN]    = 0x1F641,
    [THUMB_DN] = 0x1F44E,
    [PRAY]     = 0x1F64F,
    [PARTY]    = 0x1F389,
    [ROCKET]   = 0x1F680,
    [HEART]    = 0x2764,
    [FIRE]     = 0x1F525,
    [EYES]     = 0x1F440,
    [THINK]    = 0x1F914,
    [BUG]      = 0x1F41B,
    [CHECK]    = 0x2705,
    [CROSS]    = 0x274C,
    [HUNDRED]  = 0x1F4AF,
    [SCREAM]   = 0x1F631,
    [SHRUG]    = 0x1F937,
};

#define UNI_CW LT(_UNICODE, KC_NO)

// Left-hand home row mods
#define HOME_C LGUI_T(KC_C)
#define HOME_I LALT_T(KC_I)
#define HOME_A LCTL_T(KC_A)
#define HOME_E LSFT_T(KC_E)

// Right-hand home row mods
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_LBRC, KC_Q,    KC_Y,    KC_O,    KC_U,    KC_EQUAL,                     KC_X,    KC_L,    KC_D,    KC_W,    KC_Z,    KC_RBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_B,    HOME_C,  HOME_I,  HOME_A,  HOME_E,  KC_MINS,                      KC_K,    HOME_H,  HOME_T,  HOME_N,  HOME_S,  KC_F,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_SCLN, KC_SLASH,                     KC_J,    KC_M,    KC_G,    KC_P,    KC_V,    KC_TAB,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    LT(_MOUSE,KC_ESC),  LT(_NUMBERS,KC_ENT), LT(_NAVIGATION,KC_SPC),    LT(_SYMBOLS,KC_R), LT(_WORKSPACES,KC_BSPC), UNI_CW
                                //`--------------------------'  `--------------------------'
    ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,                      _______, KC_H,    KC_J,    KC_K,    KC_L,    _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, LGUI(KC_V), LCTL(KC_V), _______,                 _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, LGUI(KC_C), LCTL(KC_C), _______,                 _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,              _______, _______, _______
                                //`--------------------------'  `--------------------------'
    ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_COMMA, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_SCLN, LSFT(KC_SLSH),   LSFT(KC_1), KC_LBRC, LSFT(KC_9), LSFT(KC_0), KC_RBRC, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LSFT(KC_3), LSFT(KC_6), KC_EQL, LSFT(KC_MINS), LSFT(KC_4), LSFT(KC_8),    LSFT(KC_QUOT), KC_BSPC, KC_TAB, KC_SPC, KC_ENT, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, LSFT(KC_COMMA), LSFT(KC_BSLS), KC_MINS, LSFT(KC_DOT), KC_SLSH,    KC_QUOT, LSFT(KC_7), KC_GRV, LSFT(KC_GRV), LSFT(KC_EQL), _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    LSFT(KC_SCLN), LSFT(KC_2), LSFT(KC_5),    _______, _______, _______
                                //`--------------------------'  `--------------------------'
    ),

    [_WORKSPACES] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, LSFT(LGUI(KC_1)), LSFT(LGUI(KC_2)), LSFT(LGUI(KC_3)), LSFT(LGUI(KC_4)), LSFT(LGUI(KC_5)),    LSFT(LGUI(KC_6)), LSFT(LGUI(KC_7)), LSFT(LGUI(KC_8)), LSFT(LGUI(KC_9)), LSFT(LGUI(KC_0)), _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),        LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,              _______, _______, _______
                                //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                      _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,              MS_BTN1, MS_BTN2, _______
                                //`--------------------------'  `--------------------------'
    ),

    [_UNICODE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        UM(PARTY), UM(ROCKET), UM(HEART), UM(FIRE), UM(EYES), UM(THINK),           _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        UM(PRAY), UM(THUMB_UP), UM(SMILE), UM(ROFL), UM(FROWN), UM(THUMB_DN),      _______, KC_BSPC, KC_TAB,  KC_SPC,  KC_ENT,  _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        UM(BUG), UM(CHECK), UM(CROSS), UM(HUNDRED), UM(SCREAM), UM(SHRUG),         _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,              _______, UC_NEXT, _______
                                //`--------------------------'  `--------------------------'
    ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                        KC_K,    KC_7,    KC_8,    KC_9,    LSFT(KC_5), _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_BSPC, KC_TAB,  KC_SPC,  KC_ENT,  _______,                        KC_G,    KC_4,    KC_5,    KC_6,    KC_MINS, LSFT(KC_EQL),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                        KC_J,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,              KC_0,    KC_DOT,  LSFT(KC_8)
                                //`--------------------------'  `--------------------------'
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UNI_CW:
            if (record->tap.count && record->event.pressed) {
                caps_word_toggle();
                return false;
            }
            break;
    }
    return true;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_LAYER_TAP(keycode) && QK_LAYER_TAP_GET_TAP_KEYCODE(keycode) == KC_BSPC)
        return false;

    if (IS_RETRO(keycode))
        return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            return true;
        default:
            return false;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    // Disable chordal hold for LT keys — always treat as hold
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return true;
    }
    // Fall back to default chordal hold behavior for everything else (home row mods)
    return get_chordal_hold_default(tap_hold_record, other_record);
}
