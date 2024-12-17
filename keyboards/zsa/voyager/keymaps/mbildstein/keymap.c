#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/sentence_case.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layer_names {
  BASE_0,
  NAV_1,
  MOUSE_2,
  NUM_3,
  SYM_4,
  SYS_5,
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  CP_LINK,
  EN_DASH,
  ST_MACRO_2,
  ST_MACRO_3,
  M_ABKS,
  M_BRKS,
  M_CBRS,
  M_PRNS,
  EM_DASH,
  QUOP,
  SENT_END,
  M_AND,
  M_ION,
  M_JUST,
  M_MENT,
  M_NION,
  M_QUE,
  M_VER,
  M_WHICH,
  M_XES,
  M_YOU,
  M_COMMA,
  M_DASH,
  M_EQ,
  M_WSPC,
  WIN_SW,
};

// --------------------------
// aliases for tap dance keys
// --------------------------

// layer BASE_0
#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LCTL, KC_D)
#define HOME_F MT(MOD_LSFT, KC_F)
#define HOME_J MT(MOD_RSFT, KC_J)
#define HOME_K MT(MOD_RCTL, KC_K)
#define HOME_L MT(MOD_RALT, KC_L)
#define HOME_SC MT(MOD_RGUI, KC_SCLN)
#define LT4_ESC LT(SYM_4,KC_ESCAPE)
#define LT4_TAB LT(SYM_4,KC_TAB)
#define LT1_SPC LT(NAV_1,KC_SPACE)
#define LT3_ENT LT(NUM_3,KC_ENTER)
#define LT5_BSP LT(SYS_5,KC_BSPC)
#define MAGIC QK_AREP
// layer NAV_1
#define ALT_F4 LALT(KC_F4)
#define PRV_WRD LCTL(KC_LEFT)
#define NXT_WRD LCTL(KC_RIGHT)
#define CPY_ALL TD(D01)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define UNDO TD(D02)
// layer MOUSE_2
#define TO_BASE TO(BASE_0)
// layer NUM_3

// layer SYM_4

// layer SYS_5
// No custom definitions

enum tap_dance_codes {
  D00,     // *** not used ***
  D01,     // tap: [Ctrl-C] | hold: [Ctrl-A] *** not used ***
  D02,     // tap: [Ctrl-Z] | hold: [Ctrl-Y] | tap-hold: [Ctrl-Shift-Z] *** not used ***
  D03,     // tap: Left Arrow | hold: Home
  D04,     // tap: Right Arrow | hold: End
  D05,     // tap: 7 | hold: F7
  D06,     // tap: 8 | hold: F8
  D07,     // tap: 9 | hold: F9
  D08,     // tap: 4 | hold: F4
  D09,     // tap: 5 | hold: F5
  D10,     // tap: 6 | hold: F6
  D11,     // tap: 1 | hold: F1
  D12,     // tap: 2 | hold: F2
  D13,     // tap: 3 | hold: F3
  D14,     // tap: 0 | hold: F10
  D15,     // tap: ! | hold: GUI ◆
  D16,     // tap: @ | hold: Alt ⎇
  D17,     // tap: # | hold: Ctrl ⎈
  D18,     // tap: $ | hold: Shift ⇧
  D19,     // tap: SPC | hold: _
  D20,     // tap: . | hold: ". [one-shot shift]"
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_0] = LAYOUT_voyager(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     /* SPLIT */  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOTE,
    WIN_SW,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,     /* SPLIT */  KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SC, QUOP,
    CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     /* SPLIT */  KC_N,    KC_M,    KC_COMM, TD(D20), KC_SLSH, KC_MINS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LT4_ESC, QK_REP,   /* SPLIT */  MAGIC,   LT4_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        LT1_SPC, LT3_ENT,  /* SPLIT */  QK_LEAD, LT5_BSP
  ),
  [NAV_1] = LAYOUT_voyager(
    XXXXXXX, XXXXXXX, ALT_F4,  XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, PRV_WRD, KC_PGDN, KC_PGUP, NXT_WRD, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  /* SPLIT */  XXXXXXX, TD(D03), KC_DOWN, KC_UP,   TD(D04), XXXXXXX,
    XXXXXXX, CPY_ALL, CUT,     PASTE,   UNDO,    XXXXXXX,  /* SPLIT */  XXXXXXX, CP_LINK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_DEL
  ),
  [MOUSE_2] = LAYOUT_voyager(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO_BASE,  /* SPLIT */  KC_APP,  KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX,  /* SPLIT */  KC_BTN2, KC_BTN1
  ),
  [NUM_3] = LAYOUT_voyager(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  KC_PERC, TD(D05), TD(D06), TD(D07), KC_MINS, KC_NUM,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  /* SPLIT */  KC_COLN, TD(D08), TD(D09), TD(D10), KC_DOT,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  KC_HASH, TD(D11), TD(D12), TD(D13), KC_SLSH, EN_DASH,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, TD(D14), KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______,  /* SPLIT */  XXXXXXX, KC_BSPC
  ),
  [SYM_4] = LAYOUT_voyager(
    XXXXXXX, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, XXXXXXX,
    XXXXXXX, TD(D15), TD(D16), TD(D17), TD(D18), KC_PERC,  /* SPLIT */  KC_CIRC, KC_AMPR, KC_EQL,  KC_PIPE, XXXXXXX, KC_GRV,
    XXXXXXX, M_ABKS,  M_BRKS,  M_CBRS,  M_PRNS,  XXXXXXX,  /* SPLIT */  XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_BSLS, EM_DASH,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  /* SPLIT */  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        TD(D19), _______,  /* SPLIT */  XXXXXXX, KC_BSPC
  ),
  [SYS_5] = LAYOUT_voyager(
    XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, UG_NEXT, UG_TOGG,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, DT_DOWN, DT_UP,   DT_PRNT, XXXXXXX,  /* SPLIT */  XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /* SPLIT */  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_MPLY, KC_MUTE,  /* SPLIT */  XXXXXXX, XXXXXXX
  ),
};


// -----------
// Combo logic
// -----------

#ifdef COMBO_ENABLE
#include "combos.h"
#endif


// ------------
// Leader logic
// ------------

#ifdef LEADER_ENABLE
#include "leader_sequences.h"
#endif

// ------------------
// Quopostrokey logic
// ------------------

static bool process_quopostrokey(uint16_t keycode, keyrecord_t* record) {
  static bool within_word = false;

  if (keycode == QUOP) {
    if (record->event.pressed) {
      if (within_word) {
        tap_code(KC_QUOT);
      } else {
        SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
    }
    return false;
  }

  switch (keycode) {  // Unpack tapping keycode for tap-hold keys.
#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

  // Determine whether the key is a letter.
  switch (keycode) {
    case KC_A ... KC_Z:
      within_word = true;
      break;

    default:
      within_word = false;
  }

  return true;
}


// --------------------------
// Alt repeat key definitions
// --------------------------

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case HOME_A: return M_AND;          // A => ND
        case KC_B: return KC_R;             // B => R
        case KC_C: return KC_E;             // C => E
        case HOME_D: return KC_E;           // D => E
        case KC_E: return KC_D;             // E => D
        case HOME_F: return KC_R;           // F => R
        case KC_G: return KC_R;             // G => R
        case KC_H: return KC_U;             // H => U
        case KC_I: return M_ION;            // I => ON
        case HOME_J: return M_JUST;         // J => UST
        case HOME_K: return KC_I;           // K => I
        case HOME_L: return KC_O;           // L => O
        case KC_M: return M_MENT;           // M => ENT
        case KC_N: return M_NION;           // N => ION
        case KC_O: return KC_L;             // O => L
        // P => n/a
        case KC_Q: return M_QUE;            // Q => UE
        case KC_R: return KC_T;             // R => T
        case HOME_S: return KC_W;           // S => W
        case KC_T: return KC_R;             // T => R
        case KC_U: return KC_N;             // U => N
        case KC_V: return M_VER;            // V => ER
        case KC_W: return M_WHICH;          // W => HICH
        case KC_X: return M_XES;            // X => ES
        case KC_Y: return M_YOU;            // Y => OU
        case KC_Z: return KC_A;             // Z => A
        case KC_DOT: return SENT_END;       // . => " [oneshot shift]"
        case KC_EXCLAIM: return SENT_END;   // ! => " [oneshot shift]"
        case KC_QUESTION: return SENT_END;  // ? => " [oneshot shift]"
        case KC_COMM: return M_COMMA;      // , => " but"
        case KC_MINS: return M_DASH;       // - => >
        case KC_EQL: return M_EQ;         // = => >
        case LT1_SPC: return M_WSPC;        // " " => the
    }

    return XXXXXXX;  // Defer to no output.
}


// -------------------------
// Process record user logic
// -------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_quopostrokey(keycode, record)) { return false; }
  if (!process_sentence_case(keycode, record)) { return false; }

  switch (keycode) {
    case CP_LINK:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_V)) SS_DELAY(100) SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(100) SS_LCTL(SS_TAP(X_K)) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
    }
    break;
    case EN_DASH:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_2) ));
    }
    break;
    case M_ABKS:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case M_BRKS:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_RBRC) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case M_CBRS:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RBRC)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case M_PRNS:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(100) SS_LSFT(SS_TAP(X_0)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case EM_DASH:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    }
    break;
    case SENT_END:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SPACE));
        add_oneshot_mods(MOD_BIT(KC_LSFT));
    }
    break;
    case M_AND:
    if (record->event.pressed) {
        SEND_STRING("nd");
    }
    break;
    case M_ION:
    if (record->event.pressed) {
        SEND_STRING("on");
    }
    break;
    case M_JUST:
    if (record->event.pressed) {
        SEND_STRING("ust");
    }
    break;
    case M_MENT:
    if (record->event.pressed) {
        SEND_STRING("ent");
    }
    break;
    case M_NION:
    if (record->event.pressed) {
        SEND_STRING("ion");
    }
    break;
    case M_QUE:
    if (record->event.pressed) {
        SEND_STRING("ue");
    }
    break;
    case M_VER:
    if (record->event.pressed) {
        SEND_STRING("er");
    }
    break;
    case M_WHICH:
    if (record->event.pressed) {
        SEND_STRING("hich");
    }
    break;
    case M_XES:
    if (record->event.pressed) {
        SEND_STRING("es");
    }
    break;
    case M_YOU:
    if (record->event.pressed) {
        SEND_STRING("ou");
    }
    break;
    case M_COMMA:
    if (record->event.pressed) {
        SEND_STRING(" but");
    }
    break;
    case M_DASH:
    if (record->event.pressed) {
        SEND_STRING("> ");
    }
    break;
    case M_EQ:
    if (record->event.pressed) {
        SEND_STRING("> ");
    }
    break;
    case M_WSPC:
    if (record->event.pressed) {
        SEND_STRING("the");
    }
    break;
    case WIN_SW:
    if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_TAB))));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


// ---------------
// Achordion logic
// ---------------

void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT1_SPC:
        case LT3_ENT:
        case LT4_TAB:
        case LT4_ESC:
        case LT5_BSP:
        return 0; // Bypass Achordion for these keys.
    }

    return 800; // Otherwise use a timeout of 800 ms.
}


// ---------------
// Tap dance logic
// ---------------

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[21];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(KC_TAB)));
        tap_code16(LALT(LCTL(KC_TAB)));
        tap_code16(LALT(LCTL(KC_TAB)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(KC_TAB)));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(LALT(LCTL(KC_TAB)));
            break;
        case SINGLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(KC_TAB))); register_code16(LALT(LCTL(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_TAB))); register_code16(LALT(LCTL(KC_TAB)));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_TAB))); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(KC_TAB))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_TAB))); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_A)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_C)); register_code16(LCTL(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_A)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Z));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_Y)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        case DOUBLE_HOLD: register_code16(LCTL(LSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_Y)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LSFT(KC_Z))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_7);
        tap_code16(KC_KP_7);
        tap_code16(KC_KP_7);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_7);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_KP_7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_KP_7); register_code16(KC_KP_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_7); register_code16(KC_KP_7);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_7); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_8);
        tap_code16(KC_KP_8);
        tap_code16(KC_KP_8);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_8);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_KP_8); break;
        case SINGLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_KP_8); register_code16(KC_KP_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_8); register_code16(KC_KP_8);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_8); break;
        case SINGLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_8); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_9);
        tap_code16(KC_KP_9);
        tap_code16(KC_KP_9);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_9);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_KP_9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_KP_9); register_code16(KC_KP_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_9); register_code16(KC_KP_9);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_9); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_4);
        tap_code16(KC_KP_4);
        tap_code16(KC_KP_4);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_4);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_KP_4); break;
        case SINGLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_KP_4); register_code16(KC_KP_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_4); register_code16(KC_KP_4);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_4); break;
        case SINGLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_4); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_5);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_KP_5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_KP_5); register_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_5); register_code16(KC_KP_5);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_5); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_6);
        tap_code16(KC_KP_6);
        tap_code16(KC_KP_6);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_6);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_KP_6); break;
        case SINGLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_KP_6); register_code16(KC_KP_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_6); register_code16(KC_KP_6);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_6); break;
        case SINGLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_6); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_1);
        tap_code16(KC_KP_1);
        tap_code16(KC_KP_1);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_1);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_KP_1); break;
        case SINGLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_KP_1); register_code16(KC_KP_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_1); register_code16(KC_KP_1);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_1); break;
        case SINGLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_1); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_2);
        tap_code16(KC_KP_2);
        tap_code16(KC_KP_2);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_2);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_2); break;
        case SINGLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_KP_2); register_code16(KC_KP_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_2); register_code16(KC_KP_2);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_2); break;
        case SINGLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_2); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_3);
        tap_code16(KC_KP_3);
        tap_code16(KC_KP_3);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_3);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_KP_3); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_KP_3); register_code16(KC_KP_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_3); register_code16(KC_KP_3);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_3); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_3); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_0);
        tap_code16(KC_KP_0);
        tap_code16(KC_KP_0);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_0);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_KP_0); break;
        case SINGLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_KP_0); register_code16(KC_KP_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_0); register_code16(KC_KP_0);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_0); break;
        case SINGLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_0); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EXLM);
        tap_code16(KC_EXLM);
        tap_code16(KC_EXLM);
    }
    if(state->count > 3) {
        tap_code16(KC_EXLM);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_EXLM); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_EXLM); register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EXLM); register_code16(KC_EXLM);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_EXLM); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EXLM); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_AT);
        tap_code16(KC_AT);
        tap_code16(KC_AT);
    }
    if(state->count > 3) {
        tap_code16(KC_AT);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_AT); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_AT); register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AT); register_code16(KC_AT);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_AT); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AT); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
        tap_code16(KC_HASH);
    }
    if(state->count > 3) {
        tap_code16(KC_HASH);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_HASH); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: register_code16(KC_HASH); register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HASH); register_code16(KC_HASH);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_HASH); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HASH); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
    }
    if(state->count > 3) {
        tap_code16(KC_DLR);
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_DLR); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(KC_DLR); register_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DLR); register_code16(KC_DLR);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(KC_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DLR); break;
    }
    dance_state[18].step = 0;
}
void on_dance_19(tap_dance_state_t *state, void *user_data);
void dance_19_finished(tap_dance_state_t *state, void *user_data);
void dance_19_reset(tap_dance_state_t *state, void *user_data);

void on_dance_19(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

void dance_19_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(tap_dance_state_t *state, void *user_data);
void dance_20_finished(tap_dance_state_t *state, void *user_data);
void dance_20_reset(tap_dance_state_t *state, void *user_data);

void on_dance_20(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if (state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_20_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            tap_code16(LSFT(KC_DOT));
            break;
        case DOUBLE_TAP:
            SEND_STRING(". ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOT);
            register_code16(KC_DOT);
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
    }
    dance_state[20].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [D00] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [D01] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [D02] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [D03] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [D04] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [D05] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [D06] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [D07] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [D08] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [D09] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [D10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [D11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [D12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [D13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [D14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [D15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [D16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [D17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [D18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [D19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
        [D20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
};
