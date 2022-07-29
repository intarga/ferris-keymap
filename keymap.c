#include QMK_KEYBOARD_H

enum ferris_layers {
  _COLEMAK,
  _LOWER,
  _RAISE
};

// Left-hand home row mods
// #define HOME_A LSFT_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_T LGUI_T(KC_T)

// Right-hand home row mods
#define HOME_N RGUI_T(KC_N)
#define HOME_E LALT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
// #define HOME_O RSFT_T(KC_O)

// Norwegian letters
#define NO_AE LALT(KC_QUOT)
#define NO_AA LALT(KC_A)
#define NO_OE LALT(KC_O)

// Ctrl U and D
#define CTRL_U LCTL(KC_U)
#define CTRL_D LCTL(KC_D)

// Layer keys
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( /* COLEMAK */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    HOME_R,  HOME_S,  HOME_T,  KC_D,            KC_H,    HOME_N,  HOME_E,  HOME_I,  KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                    KC_LSFT, KC_SPC,  RAISE,   LOWER
  ) ,

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,         KC_0,    KC_1,    KC_2,    KC_3,    KC_GRV,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   QK_BOOT,         KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  DEBUG,           KC_EQL,  KC_7,    KC_8,    KC_9,    KC_BSLS,
                                    _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_MRWD, KC_MFFD, KC_LBRC, KC_RBRC, NO_AA,           KC_VOLU, CTRL_D,  CTRL_U,  KC_BRIU, KC_ESC,
    KC_BSPC, KC_INS,  KC_LPRN, KC_RPRN, NO_AE,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
    KC_MUTE, KC_MPLY, KC_LCBR, KC_RCBR, NO_OE,           KC_VOLD, KC_PGDN, KC_PGUP, KC_BRID, KC_ENT,
                                    _______, _______, _______, _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    // [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
