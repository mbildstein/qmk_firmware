#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  BASE_0,
  NAV_1,
  MOUSE_2,
  NUM_3,
  SYM_4,
  SYS_5,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_0] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,  /* SPLIT */  XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        _______, _______, _______, _______, _______, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_H,    _______, _______, _______, _______, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              /* SPLIT */           KC_N,    KC_M,    KC_COMM, _______, KC_SLSH, KC_MINS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______,  /* SPLIT */  _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______,  /* SPLIT */  _______, _______, _______
    ),

    [NAV_1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, _______, KC_PGDN, KC_PGUP, _______, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, _______, KC_DOWN, KC_UP,   _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, XXXXXXX,           /* SPLIT */           XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,  /* SPLIT */  XXXXXXX,          KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, KC_DEL
    ),

    [MOUSE_2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           /* SPLIT */           XXXXXXX, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,  /* SPLIT */  XXXXXXX,          KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, _______
    ),

    [NUM_3] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, _______, _______, _______, KC_MINS, KC_NUM,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, _______, _______, _______, KC_DOT,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           /* SPLIT */           _______, _______, _______, _______, KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,  /* SPLIT */  XXXXXXX,          _______, _______, _______, XXXXXXX, XXXXXXX,
                                            _______, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, KC_BSPC
    ),

    [SYM_4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, KC_PERC, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_CIRC, KC_AMPR, KC_EQL,  KC_PIPE, XXXXXXX, KC_GRV,
        XXXXXXX, _______, _______, _______, _______, XXXXXXX,           /* SPLIT */           XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,  /* SPLIT */  XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, KC_BSPC
    ),

    [SYS_5] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, UG_NEXT, UG_TOGG, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, XXXXXXX, DT_DOWN, DT_UP,   DT_PRNT, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           /* SPLIT */           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,  /* SPLIT */  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_MPLY, KC_MUTE, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [BLANK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,  /* SPLIT */  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  /* SPLIT */  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  /* SPLIT */  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,           /* SPLIT */           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,  /* SPLIT */  _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,  /* SPLIT */  _______, _______, _______ 
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
