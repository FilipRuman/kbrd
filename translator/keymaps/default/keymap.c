
#include "print.h"
#include QMK_KEYBOARD_H



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
         LGUI_T(KC_DEL),   KC_C,       KC_D,        KC_E,
                             KC_V,   LCTL_T(KC_F),        KC_R,
                             KC_B,       RALT_T(KC_G),        LT(_MS, KC_T)
 ,
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
                             XXXXXXX,             XXXXXXX,            XXXXXXX
 ,
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
                            XXXXXXX,             KC_3,               XXXXXXX
 ,
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
                            XXXXXXX,             XXXXXXX,            XXXXXXX
 ,
          // right
          _______,            MS_BTN1,             MS_LEFT,            XXXXXXX,
          _______,            MS_BTN2,             MS_DOWN,            XXXXXXX,
          _______,            XXXXXXX,             MS_UP,              XXXXXXX,
                              XXXXXXX,             MS_RGHT,            XXXXXXX,
                              XXXXXXX,             XXXXXXX,            XXXXXXX
    )
};
#include "quantum.h"


void pmw33xx_debug(void)
{
dprintf(
        "ID: 0x%02X MOT: 0x%02X DX: %d DY: %d\n",
        pmw33xx_read(0, 0x00),
        pmw33xx_read(0, 0x02),
        (int16_t)((pmw33xx_read(0, 0x04) << 8) | pmw33xx_read(0, 0x03)),
        (int16_t)((pmw33xx_read(0, 0x06) << 8) | pmw33xx_read(0, 0x05))
    );
}


void housekeeping_task_user(void) {
    static uint32_t last_print = 0;

    if (timer_elapsed32(last_print) >= 1000) {
        last_print = timer_read32();

        dprintf("|>\n");
    pmw33xx_debug();
    }
}
void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
     debug_enable=true;
     debug_matrix=true;
    // print("stringr)
   debug_keyboard=true;
   // debug_mouse=true;

}
void pointing_device_init_kb(void) {
    pmw33xx_init(0);
    pmw33xx_set_cpi(0, 800); // applies to first sensor
    pointing_device_init_user();
}

