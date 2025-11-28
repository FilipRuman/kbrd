#include "print.h"
#include QMK_KEYBOARD_H



enum _layers {
_BASE,
_FUNC,
_SYMB,
_MS
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        // left
        LT(_SYMB, KC_SPC),  KC_Z,       KC_A,        KC_Q,
        LCTL_T(KC_F2),      KC_X,       KC_S,        KC_W,
        LGUI_T(KC_ENTER),   KC_C,       KC_D,        KC_E,
                            KC_V,       KC_F,        KC_R,
                            KC_B,       KC_G,        LT(_MS, KC_T),

        // right
        RALT_T(KC_ESC),     KC_N,       KC_H,        KC_Y,
        LT(_FUNC, KC_DEL),  KC_M,       KC_J,        KC_U,
        LSFT_T(KC_BSPC),    KC_COMMA,   KC_K,        KC_I,
                            KC_DOT,     KC_L,        KC_O,
                            KC_SLASH,   KC_SEMICOLON,KC_P
    ),


    [_FUNC] = LAYOUT(
        // left
        _______,            KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,      XXXXXXX,
        _______,            KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,    XXXXXXX,
        _______,            KC_BRIGHTNESS_DOWN,  KC_MEDIA_PLAY_PAUSE,XXXXXXX,
                            KC_BRIGHTNESS_DOWN,  KC_TAB,             KC_UNDS,
                            XXXXXXX,             XXXXXXX,            XXXXXXX,

        // right
        _______,            XXXXXXX,             KC_LEFT,            XXXXXXX,
        _______,            KC_NONUS_HASH,       KC_DOWN,            KC_MINUS,
        _______,            XXXXXXX,             KC_UP,              KC_EQUAL,
                            XXXXXXX,             KC_RIGHT,           XXXXXXX,
                            XXXXXXX,             XXXXXXX,            QK_BOOT
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
        _______,            XXXXXXX,             XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,             XXXXXXX,            XXXXXXX,
        _______,            XXXXXXX,             XXXXXXX,            XXXXXXX,
                            XXXXXXX,             XXXXXXX,            XXXXXXX,
                            XXXXXXX,             XXXXXXX,            XXXXXXX,

        // right
        _______,            MS_BTN1,             MS_LEFT,            XXXXXXX,
        _______,            MS_BTN2,             MS_DOWN,            XXXXXXX,
        _______,            XXXXXXX,             MS_UP,              XXXXXXX,
                            XXXXXXX,             MS_RGHT,            XXXXXXX,
                            XXXXXXX,             XXXXXXX,            XXXXXXX
    )
};
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
   debug_enable=true;
  // debug_matrix=true;
    // print("string");
  //debug_keyboard=true;
  //debug_mouse=true;
}
