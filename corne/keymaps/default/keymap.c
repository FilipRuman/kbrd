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
                 //left
                 LCTL_T(KC_F2),   KC_Z,   KC_A, KC_Q,
                 LT(_SYMB, KC_SPC),            KC_X,   KC_S, KC_W,
                 LGUI_T(KC_ENTER), KC_C,   KC_D, KC_E,
                            KC_V,   KC_F, KC_R,
                            KC_B,   KC_G, LT(_MS, KC_T),
                 //right
                 RALT_T(KC_ESC),              KC_N,       KC_H,         KC_Y,
                 LSFT_T(KC_DEL),   KC_M,       KC_J,         KC_U,
                 LT(_FUNC, KC_BSPC),              KC_COMMA,     KC_K,         KC_I,
                                       KC_DOT,   KC_L, KC_O,
                                       KC_SLASH,   KC_SEMICOLON,      KC_P
        ),


        [_FUNC] = LAYOUT(

                //left
                _______,            KC_MEDIA_NEXT_TRACK,    KC_AUDIO_MUTE,  _______,
                _______,            KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,_______,
                _______,            KC_TAB,             KC_MEDIA_PLAY_PAUSE,_______,
                KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,_______,
                _______,                     _______,_______,
                //right
                _______,    _______,KC_LEFT,_______,
                _______,    _______,KC_DOWN,_______,
                _______,    _______,KC_UP,_______,
                _______,    KC_RIGHT,_______,
                _______,    _______,QK_BOOT
        ),



        [_SYMB] = LAYOUT(
                //left
                _______,        _______,        KC_9,   _______,
                _______,        KC_NONUS_HASH,  KC_0,   _______,
                _______,        KC_LEFT_BRACKET,KC_1,   _______,
                                KC_LEFT_BRACKET,KC_2,   _______,
                                _______,        KC_3,KC_3,
                //right
                _______,    KC_MINUS,       KC_4,   _______,
                _______,    KC_EQUAL,       KC_5,   _______,
                _______,    KC_BACKSLASH,   KC_6,   KC_QUOT ,
                        _______,            KC_7,   _______,
                        _______,            KC_8,   QK_BOOT

        ),

        [_MS] = LAYOUT(
                //left
                _______,        _______,        _______,   _______,
                _______,        _______,  _______,   _______,
                _______,        _______,_______,   _______,
                                _______,_______,   _______,
                                _______,        _______,_______,
                //right
                _______,MS_BTN1,MS_LEFT,   _______,
                _______,MS_BTN2,MS_DOWN,  _______,
                _______,_______,MS_UP,  _______,
                        _______,MS_RGHT,   _______,
                        _______,_______,_______

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
