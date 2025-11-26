// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "print.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_1,   KC_2,   KC_3, KC_4,
        KC_5,   KC_6,   KC_7, KC_8,
        KC_9,   KC_0,   KC_A, KC_B,
        KC_C,   KC_P,   KC_E,
        KC_F,   KC_G,   KC_D,
        KC_1,   KC_2,   KC_3, KC_4,
        KC_5,   KC_6,   KC_7, KC_8,
        KC_9,   KC_0,   KC_A, KC_B,
        KC_C,   KC_P,   KC_E,
        KC_F,   KC_G,   KC_D
    )
};
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
    print("string");
  //debug_keyboard=true;
  //debug_mouse=true;
}
