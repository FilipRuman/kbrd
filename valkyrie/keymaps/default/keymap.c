#include QMK_KEYBOARD_H
#include "print.h"

enum _layers { _BASE };

// Tap Dance definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE] = LAYOUT(KC_Z, KC_A, KC_Q, LCTL_T(KC_F2), KC_X, KC_X, KC_S, KC_W, LGUI_T(KC_DEL), KC_C, KC_D, KC_E, KC_V, KC_F, KC_R, KC_B, RALT_T(KC_G), KC_F)};

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
    print("boot\n");
    dprintln("boot\n");
    uprintln("boot\n");
    dprintln("alive\n");
}

void matrix_scan_user(void) {
    static uint32_t t;

    if (timer_elapsed32(t) > 1000) {
        t = timer_read32();
        dprintln("alive\n");
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    return true;
}

void pointing_device_init_kb(void) {
    pmw33xx_init(0);
    pmw33xx_set_cpi(0, 800);
    pointing_device_init_user();
}

// Contains report from sensor #0 already, need to merge in from sensor #1
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    // From quantum/pointing_device_drivers.c
#define constrain_hid(amt) ((amt) < -127 ? -127 : ((amt) > 127 ? 127 : (amt)))

    dprintln("POINTING\n");
    mouse_report.x = constrain_hid(mouse_report.x);
    mouse_report.y = constrain_hid(mouse_report.y);

    return pointing_device_task_user(mouse_report);
}
