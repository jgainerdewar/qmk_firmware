/* Copyright 2020 gtips
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

enum custom_keycodes {
    MY_CUT = SAFE_RANGE,
    MY_COPY,
    MY_PSTE,
    MY_UNDO,
    MY_FIND,
    MY_PTSC
};

enum layers {
    BASE,
    LNAV,
    RNAV,
    LSYM,
    RSYM,
    SYM
};

// Homerow mod aliases
#define HR_A LALT_T(KC_A)
#define HR_R LCTL_T(KC_R)
#define HR_S LGUI_T(KC_S)
#define HR_T LSFT_T(KC_T)
#define HR_N RSFT_T(KC_N)
#define HR_E RGUI_T(KC_E)
#define HR_I RCTL_T(KC_I)
#define HR_O RALT_T(KC_O)


#define LAYOUT_reviung41_leftlayer(\
K01, K02, K03, K04, K05,\
K06, K07, K08, K09, K10,\
K11, K12, K13, K14, K15,\
K16, K17, K18\
)\
LAYOUT_reviung41(\
  K01, K02, K03, K04, K05, K06,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,\
  K07, K08, K09, K10, K11, K12,    KC_NO, KC_RSFT, KC_RGUI, KC_RCTL, KC_RALT,KC_NO,\
  K13, K14, K15, K16, K17, K18,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,\
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS\
)

#define LAYOUT_reviung41_rightlayer(\
K01, K02, K03, K04, K05,\
K06, K07, K08, K09, K10,\
K11, K12, K13, K14, K15,\
K16, K17, K18\
)\
LAYOUT_reviung41(\
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,          K01, K02, K03, K04, K05, K06,\
  KC_NO, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT,KC_NO,  K07, K08, K09, K10, K11, K12,\
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,          K13, K14, K15, K16, K17, K18,\
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS\
)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_reviung41(
    KC_ESC,  KC_Q,     KC_W,     KC_F,     KC_P,      KC_B,            KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,     KC_BSPC,
    KC_TAB,  KC_A,     HR_R,     HR_S,     HR_T,      KC_G,            KC_M,     HR_N,     HR_E,     HR_I,     HR_O,     KC_ENT,
    KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_D,      KC_V,            KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_CAPS,
                                MO(LSYM),   LT(LNAV,KC_ENT), LT(SYM,KC_SPC),   LT(RNAV, KC_TAB),    MO(RSYM)
  ),

  [LNAV] = LAYOUT_reviung41_leftlayer(
    KC_TRNS, MY_PTSC, KC_HOME, KC_UP, KC_PGUP, MY_CUT,
    KC_TRNS, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, MY_COPY,
    KC_TRNS, MY_UNDO, KC_END, MY_FIND, KC_PGDN, MY_PSTE
  ),

  [RNAV] = LAYOUT_reviung41_rightlayer(
    KC_COMM, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS,
    KC_PDOT, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS,
    KC_P0, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS
  ),

  [LSYM] = LAYOUT_reviung41_leftlayer(
    KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, 
    KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD
  ),

  [RSYM] = LAYOUT_reviung41_rightlayer(
    KC_COLN, KC_LT, KC_GT, KC_UNDS, KC_NO, KC_TRNS,
    KC_PLUS, KC_MINS, KC_EQL, KC_ASTR, KC_SCLN, KC_TRNS,
    KC_NO, KC_AMPR, KC_BSLS, KC_NO, KC_NO, KC_TRNS
  ),

  [SYM] = LAYOUT_reviung41(
    KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,      KC_COLN, KC_LT, KC_GT, KC_UNDS, KC_NO, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,      KC_PLUS, KC_MINS, KC_EQL, KC_ASTR, KC_SCLN, KC_TRNS,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,    KC_NO, KC_AMPR, KC_BSLS, KC_NO, KC_NO, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
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
