
#include "print.h"
#include QMK_KEYBOARD_H
#include "pointing_device.h"
#include "transactions.h"
#include "split_util.h"
#include "drivers/sensors/pmw33xx_common.h"



enum _layers {
_BASE,
_FUNC,
_SYMB,
_MS
};


// Tap Dance definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
         // left
         LT(_SYMB, KC_ENTER),  KC_Z,      KC_A ,        KC_Q,
         LSFT_T(KC_F2),      KC_X,       KC_S,        KC_W,
         LGUI_T(KC_DEL),  LT(_MS, KC_C),       KC_D,        KC_E,
                             KC_V,   LCTL_T(KC_F),        KC_R,
                             KC_B,       RALT_T(KC_G),         KC_T,
           // right
           KC_ESC,             KC_N,           KC_H,           KC_Y,
           LT(_FUNC, KC_SPC),  KC_M,           LCTL_T(KC_J),           KC_U,
           LSFT_T(KC_BSPC),            KC_COMMA,       KC_K,           KC_I,
                               KC_DOT,         KC_L,           KC_O,
                               KC_SLASH,       KC_SEMICOLON,   KC_P
    ),


    [_FUNC] = LAYOUT(
         // left
         _______,            KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,      XXXXXXX,
         _______,            KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,    XXXXXXX,
         _______,            KC_BRIGHTNESS_DOWN,  KC_MEDIA_PLAY_PAUSE,KC_PLUS,
                             KC_BRIGHTNESS_DOWN,  KC_TAB,             KC_UNDS,
                             XXXXXXX,             XXXXXXX,            XXXXXXX,
           // right
           _______,            XXXXXXX,             KC_LEFT,            QK_BOOT,
           _______,            KC_NONUS_HASH,       KC_DOWN,            KC_MINUS,
           _______,            XXXXXXX,             KC_UP,              KC_EQUAL,
                               XXXXXXX,             KC_RIGHT,           XXXXXXX,
                               XXXXXXX,             XXXXXXX,            KC_PSCR
    ),

    [_SYMB] = LAYOUT(
        // left
        _______,            XXXXXXX,             KC_9,               QK_BOOT,
        _______,            XXXXXXX,             KC_0,               XXXXXXX,
        _______,            KC_LEFT_BRACKET,     KC_1,               KC_QUOT,
                            KC_RIGHT_BRACKET,    KC_2,               KC_GRV,
                             XXXXXXX,             KC_3,               XXXXXXX,
           // right
           _______,            XXXXXXX,             KC_4,               XXXXXXX,
          _______,            KC_HASH,             KC_5,               KC_ASTR,
          _______,            KC_BACKSLASH,        KC_6,               KC_PIPE,
                              XXXXXXX,             KC_7,               KC_AMPR,
                              XXXXXXX,             KC_8,               XXXXXXX
    ),


    [_MS] = LAYOUT(
        // left

        _______,           _______,            _______,           _______,
        _______,           _______,            _______,           _______,
        _______,           _______,            _______,           _______,
                           _______,            _______,           _______,
                            _______,            _______,           _______,
           // right
           _______,            _______, _______            ,            _______,
          _______,            _______,MS_BTN1              ,           _______,
          _______,            _______,MS_BTN2,              _______,
                              _______,             _______,            _______,
                               _______,             _______,            _______
    )
};

#include "quantum.h"

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
}
void pointing_device_init_kb(void) {
    pointing_device_init_user();
}

void matrix_scan_user(void) {
    // Disabled during COMBINED test; pointing_device_task_combined_user
    // handles both sensors directly.
}

#define SCROLL_DIVISOR_X 150
#define SCROLL_DIVISOR_Y 150
#define MOVE_SCALE_NUMERATOR 1
#define MOVE_SCALE_DENOMINATOR 1

static int16_t scroll_accum_x = 0;
static int16_t scroll_accum_y = 0;

// USB mouse reports are int8_t; clamp so extreme deltas don't wrap around.
static inline int8_t clamp_mouse_axis(int16_t value) {
    if (value > 127) return 127;
    if (value < -127) return -127;
    return (int8_t)value;
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    report_mouse_t report = {0};

    // Sensors only act as mouse/scroll while the mouse layer is active.
    if (!layer_state_is(_MS)) {
        return report;
    }

    // Right sensor moves the cursor.
    int16_t move_x = ((int16_t)right_report.x * MOVE_SCALE_NUMERATOR) / MOVE_SCALE_DENOMINATOR;
    int16_t move_y = ((int16_t)right_report.y * MOVE_SCALE_NUMERATOR) / MOVE_SCALE_DENOMINATOR;
    report.x = clamp_mouse_axis(move_x);
    report.y = clamp_mouse_axis(move_y);

    // Left sensor scrolls horizontally/vertically.
    // Accumulate fractional movement so slow slides still register.
    scroll_accum_x += (int16_t)left_report.x;
    scroll_accum_y += (int16_t)left_report.y;

    int16_t scroll_h = scroll_accum_x / SCROLL_DIVISOR_X;
    int16_t scroll_v = -scroll_accum_y / SCROLL_DIVISOR_Y;
    scroll_accum_x %= SCROLL_DIVISOR_X;
    scroll_accum_y %= SCROLL_DIVISOR_Y;

    report.h = clamp_mouse_axis(scroll_h);
    report.v = clamp_mouse_axis(scroll_v);

    return report;
}

