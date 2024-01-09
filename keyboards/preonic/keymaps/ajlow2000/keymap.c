/* Copyright 2015-2021 Jack Humbert
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

enum layers {
    QWERTY,
    SYM,
    NAV,
    NUM,
    GAME_OVERLAY,
    RECURVA,
    STURDY,
    COLEMAK_DH,
};

enum tap_dances {
    COPY_PASTE = 0,
};
tap_dance_action_t tap_dance_actions[] = {
    [COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(C(KC_V), C(KC_C)),
};

/* Tap Dance */
#define TD_CV TD(COPY_PASTE)

/* Mod Taps */
#define MT_ESC MT(MOD_LCTL, KC_ESC)
#define MT_ENT MT(MOD_RCTL, KC_ENT)

/* Layer stuff */
#define DF_Q DF(QWERTY)
#define DF_R DF(RECURVA)
#define DF_S DF(STURDY)
#define DF_C DF(COLEMAK_DH)
#define GAME TO(GAME_OVERLAY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_preonic_grid(
        TD_CV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    G(KC_L),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TAB,
        MT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  TT(SYM), TT(NAV), KC_SPC,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),

    [SYM] = LAYOUT_preonic_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_BSLS, KC_QUOT, KC_DQUO, KC_PERC, KC_QUES, KC_EXLM, KC_RBRC, KC_LBRC, KC_GRV,  KC_COLN, _______,
        _______, KC_CIRC, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR, KC_AT,   KC_RPRN, KC_LPRN, KC_TILD, KC_SCLN, _______,
        _______, KC_LT,   KC_PIPE, KC_MINS, KC_GT,   KC_SLSH, KC_PLUS, KC_RCBR, KC_LCBR, KC_HASH, KC_DOT,  _______,
        XXXXXXX, _______, _______, _______, _______, TG(SYM), _______, _______, _______, _______, _______, XXXXXXX
    ),

    [NAV] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        QK_BOOT, _______, _______, KC_MS_U, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, G(KC_L),
        _______, DF_Q,    KC_MS_L, KC_MS_D, KC_MS_R, GAME,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, DF_R,    DF_S,    DF_C,    _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______,
        XXXXXXX, _______, _______, _______, KC_BTN1, KC_BTN2, TG(NAV), _______, _______, _______, _______, XXXXXXX
    ),

    [NUM] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F4,   KC_F7,   KC_F10,  _______, KC_SLSH, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, KC_F2,   KC_F5,   KC_F8,   KC_F11,  _______, KC_COLN, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, KC_F3,   KC_F6,   KC_F9,   KC_F12,  _______, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_0,    _______,
        XXXXXXX, _______, _______, _______, _______, TG(NUM), TG(NUM), _______, _______, _______, _______, XXXXXXX
    ),

    [GAME_OVERLAY] = LAYOUT_preonic_grid(
        KC_ESC,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_BSPC,
        KC_TAB,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_ESC,
        KC_LCTL, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_ENT,
        KC_LSFT, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_F4,
        XXXXXXX, KC_LALT, XXXXXXX, KC_LCTL, KC_SPC,  KC_SPC,  TG(GAME_OVERLAY), KC_SPC,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX
    ),

    // https://github.com/GalileoBlues/Recurva
    [RECURVA] = LAYOUT_preonic_grid(
        TD_CV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    G(KC_L),
        KC_TAB,  KC_F,    KC_R,    KC_D,    KC_P,    KC_V,    KC_Q,    KC_J,    KC_U,    KC_O,    KC_Y,    KC_TAB,
        MT_ESC,  KC_S,    KC_N,    KC_T,    KC_C,    KC_B,    KC_DOT,  KC_H,    KC_E,    KC_A,    KC_I,    MT_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_K,    KC_G,    KC_W,    KC_M,    KC_L,    KC_SCLN, KC_QUOT, KC_COMM, KC_RSFT,
        XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  TT(SYM), TT(NAV), KC_SPC,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),

    // TODO - implement magic key (placeholder is asterisk)
    // https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md
    [STURDY] = LAYOUT_preonic_grid(
        TD_CV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    G(KC_L),
        KC_TAB,  KC_V,    KC_M,    KC_L,    KC_C,    KC_P,    KC_B,    KC_ASTR, KC_U,    KC_O,    KC_COMM, KC_TAB,
        MT_ESC,  KC_S,    KC_T,    KC_R,    KC_D,    KC_Y,    KC_F,    KC_N,    KC_E,    KC_A,    KC_I,    MT_ENT,
        KC_LSFT, KC_X,    KC_K,    KC_J,    KC_G,    KC_W,    KC_Z,    KC_H,    KC_QUOT, KC_QUES, KC_DOT,  KC_RSFT,
        XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  TT(SYM), TT(NAV), KC_SPC,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),

    //
    [COLEMAK_DH] = LAYOUT_preonic_grid(
        TD_CV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    G(KC_L),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TAB,
        MT_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    MT_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  TT(SYM), TT(NAV), KC_SPC,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),

    // [PLACEHOLDER] = LAYOUT_preonic_grid(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    // ),
};
