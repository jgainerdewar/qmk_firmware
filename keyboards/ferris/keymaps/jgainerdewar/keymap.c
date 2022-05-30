#include QMK_KEYBOARD_H

///// FERRIS SWEEP /////

enum custom_keycodes {
    MY_CUT = SAFE_RANGE,
    MY_COPY,
    MY_PSTE,
    MY_UNDO,
    MY_FIND,
    MY_PTSC,
};

enum layers {
    BASE,
    LNAV,
    RNAV,
    LSYM,
    RSYM,
};

// Homerow mod aliases
#define HR_A LALT_T(KC_A)
#define HR_S LCTL_T(KC_S)
#define HR_D LGUI_T(KC_D)
#define HR_F LSFT_T(KC_F)
#define HR_J RSFT_T(KC_J)
#define HR_K RGUI_T(KC_K)
#define HR_L RCTL_T(KC_L)
#define HR_QT RALT_T(KC_QUOT)


#define LAYOUT_ferris_leftlayer(\
K01, K02, K03, K04, K05,\
K06, K07, K08, K09, K10,\
K11, K12, K13, K14, K15\
)\
LAYOUT_split_3x5_2(\
  K01, K02, K03, K04, K05,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  K06, K07, K08, K09, K10,    KC_NO, KC_LSFT, KC_LGUI, KC_LCTL, KC_LALT,\
  K11, K12, K13, K14, K15,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
         KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS\
)

#define LAYOUT_ferris_rightlayer(\
K01, K02, K03, K04, K05,\
K06, K07, K08, K09, K10,\
K11, K12, K13, K14, K15\
)\
LAYOUT_split_3x5_2(\
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  K01, K02, K03, K04, K05,\
  KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, KC_NO,  K06, K07, K08, K09, K10,\
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  K11, K12, K13, K14, K15,\
                           KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS\
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, 
    HR_A, HR_S, HR_D, HR_F, KC_G,   KC_H, HR_J, HR_K, HR_L, HR_QT, 
    KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
    LT(LSYM,KC_BSPC), LT(LNAV,KC_TAB),  LT(RNAV,KC_ENT), LT(RSYM,KC_SPC)
  ),
  [LNAV] = LAYOUT_ferris_leftlayer(
    MY_PTSC, KC_HOME, KC_UP, KC_PGUP, MY_CUT,
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, MY_COPY,
    MY_UNDO, KC_END, MY_FIND, KC_PGDN, MY_PSTE
  ),
  [RNAV] = LAYOUT_ferris_rightlayer(
    KC_COMM, KC_P7, KC_P8, KC_P9, KC_PPLS,
    KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PMNS,
    KC_P0, KC_P1, KC_P2, KC_P3, KC_PSLS
  ),
  [LSYM] = LAYOUT_ferris_leftlayer(
    KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, 
    KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD
  ),
  [RSYM] = LAYOUT_ferris_rightlayer(
    KC_COLN, KC_LT, KC_GT, KC_UNDS, KC_NO,
    KC_PLUS, KC_MINS, KC_EQL, KC_ASTR, KC_SCLN,
    KC_NO, KC_AMPR, KC_BSLS, KC_NO, KC_NO
  ),
};

const uint16_t PROGMEM combo_esc[] = {KC_Q, HR_A, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {HR_A,KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_caps, KC_CAPS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_CUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("x"));
      }
      return false;
    case MY_COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("c"));
      }
      return false;
    case MY_PSTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("v"));
      }
      return false;
    case MY_UNDO:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("z"));
      }
      return false;
    case MY_FIND:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("f"));
      }
      return false;
    case MY_PTSC:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LSFT("4")));
      }
      return false;
  }
  return true;
}
