// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// enum layers {
//     _QWERTY,
//     _COLMAK,
//     _RAISE,
//     _LOWER,
//     _ADJUST
// };

enum custom_keycodes {
    MY_CUT = SAFE_RANGE,
    MY_COPY,
    MY_PSTE,
    MY_UNDO,
    MY_FIND,
    MY_PTSC
};

enum layers {
    QWERTY,
    COLMAK,
    LNAV,
    RNAV,
    SYM
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

// Colmak DH homerow mod aliases
#define CR_A LALT_T(KC_A)
#define CR_R LCTL_T(KC_R)
#define CR_S LGUI_T(KC_S)
#define CR_T LSFT_T(KC_T)
#define CR_N RSFT_T(KC_N)
#define CR_E RGUI_T(KC_E)
#define CR_I RCTL_T(KC_I)
#define CR_O RALT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  NO  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |Bkspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   '  |  ENT |
 * |------+------+------+------+------+------| LALT  |    |   NO  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTL  | LGUI | LNAV | / Tab   /       \Space \  | RNAV | RGUI | RALT |
 *                   |      |      |      |/(SYM)  /         \ (SYM)\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_NO,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_CAPS,  KC_A,   HR_S,    HR_D,    HR_F,    KC_G,                     KC_H,    HR_J,    HR_K,    HR_L,    HR_QT, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LALT,      KC_NO,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,KC_RSFT,
              KC_LCTL,    KC_LGUI, MO(LNAV), LT(SYM, KC_TAB),    LT(SYM, KC_SPC),   MO(RNAV), KC_RGUI, KC_RALT
),

 [COLMAK] = LAYOUT(
  KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,  KC_TRNS,
  KC_TRNS,  KC_A,   CR_R,    CR_S,    CR_T,    KC_G,                     KC_M,    CR_N,    CR_E,    CR_I,    CR_O, KC_TRNS,
  KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_ESC,   KC_NO,    KC_K,    KC_H,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  QWT |  COL |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |   {  |   }  |  |   |                    |   :  |   <  |   >  |  _   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |-------.    ,-------|   +  |   -  |   =  |   *  |   ;  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |  ~   |-------|    |-------|      |   &  |   \  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTL  | LGUI | LNAV | /Enter  /       \Space \  | RNAV | RGUI | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[SYM] = LAYOUT(
    KC_TRNS, DF(QWERTY), DF(COLMAK), KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                    KC_COLN, KC_LT, KC_GT, KC_UNDS, KC_NO, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,                    KC_PLUS, KC_MINS, KC_EQL, KC_ASTR, KC_SCLN, KC_TRNS,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,KC_TRNS, KC_TRNS, KC_NO, KC_AMPR, KC_BSLS, KC_NO, KC_NO, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  | F3   |  F4  |  F5  |                    |   F6 | F7   |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |PTSC  | HOME |  UP  |PGUP  | CUT  |                    |   ,  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | CTL  | LEFT | DOWN |RIGHT | COPY |-------.    ,-------|   .  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|RGB_TOG|    |       |------+------+------+------+------+------|
 * |      | UNDO | END  | FIND | PGDN |PASTE |-------|    |-------|   0  |   7  |   8  |   9  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[LNAV] = LAYOUT(
  KC_TRNS, KC_F1,   KC_F2,  KC_F3,    KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
  KC_TRNS, MY_PTSC, KC_HOME, KC_UP, KC_PGUP, MY_CUT,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_TRNS, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, MY_COPY,                     KC_NO,   KC_RSFT, KC_RGUI, KC_RCTL, KC_RALT, KC_TRNS,
  KC_TRNS, MY_UNDO, KC_END, MY_FIND, KC_PGDN, MY_PSTE,   RGB_TOG, KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

[RNAV] = LAYOUT(
  KC_TRNS, KC_F1,   KC_F2,  KC_F3,    KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_COMM, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,  KC_TRNS,
  KC_TRNS, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, KC_NO,                      KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG, KC_TRNS,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
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