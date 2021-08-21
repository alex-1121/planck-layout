/* Copyright 2015-2017 Jack Humbert
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

enum planck_layers {
    _QWERTY,
    _COLEMAK,
    _SYM,
    _ADJUST,
    _NUM,
    _NAV,
    _MEDIA,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
};

#define SYM   MO(_SYM)
#define NUM   MO(_NUM)
#define NAV   MO(_NAV)
#define MEDIA MO(_MEDIA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------.
 * |Tab(Alt)|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc(Cmd)|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl   | Ctrl | Alt  | GUI  |  Num | Space| Space| Sym  | Arrow|      | Left |Right |
 * `-------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    LALT_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    LGUI_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G, KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,        KC_LCTL, KC_LALT, KC_LGUI, NUM, KC_SPC, KC_SPC, SYM,   NAV,     MEDIA,   KC_LEFT, KC_RIGHT
),

/* Colemak
 * ,-------------------------------------------------------------------------------------.
 * |Tab(Alt)|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc(Cmd)|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl   | Ctrl | Alt  | GUI  |  Num | Space| Space| SYM  | Arrow|      | Left |Right |
 * `-------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    LALT_T(KC_TAB), KC_Q,    KC_W,    KC_F,    KC_P,  KC_G, KC_J,    KC_L, KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LGUI_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,  KC_D, KC_H,    KC_N, KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_K,    KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,        KC_LCTL, KC_LALT, KC_LGUI, NUM, KC_SPC, KC_SPC,  SYM,  NAV,    MEDIA,   KC_LEFT, KC_RIGHT
),

/* Numpad + F-row
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |   +  |   7  |   8  |   9  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |      |   -  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   .  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_PLUS, KC_7,    KC_8,     KC_9,    _______, KC_BSPC,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_MINS, KC_4,    KC_5,     KC_6,    _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DOT,  KC_1,    KC_2,     KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    _______,  _______, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |   {  |   }  |      |   +  |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   !  |   @  |   #  |   $  |   (  |   )  |   =  |   -  |   _  |   ~  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   %  |   ^  |   &  |   *  |   [  |   ]  |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_GRV,  _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_PLUS, _______, _______, KC_BSPC,
    KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_EQL,  KC_MINS, KC_UNDS, KC_TILD, KC_PIPE,
    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Num + Sym)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug |      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |CGtogg|      |      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, _______, _______, CG_TOGG, _______, _______, QWERTY,  COLEMAK,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | PgUp |  Up  | PgDn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,    KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Media
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      | Vol- | Play |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Prev | Vol+ | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Prev | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,  KC_MPLY, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD,  KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_MPRV, KC_MNXT
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}
