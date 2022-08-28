#include QMK_KEYBOARD_H

enum ferris_layers {
  _COLEMAK,
  _BEAKL,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Left-hand home row mods
#define HOME_R LCTL_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define BEAK_I LCTL_T(KC_I)
#define BEAK_E LALT_T(KC_E)
#define BEAK_A LGUI_T(KC_A)

// Right-hand home row mods
#define HOME_N RGUI_T(KC_N)
#define HOME_E LALT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define BEAK_S RGUI_T(KC_S)
#define BEAK_T LALT_T(KC_T)
#define BEAK_N RCTL_T(KC_N)

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
#define COLEMAK DF(_COLEMAK)
#define BEAKL DF(_BEAKL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,    HOME_R,  HOME_S,  HOME_T,  KC_D,            KC_H,    HOME_N,  HOME_E,  HOME_I,  KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                    KC_LSFT, KC_SPC,  RAISE,   LOWER
  ),

  [_BEAKL] = LAYOUT(
    KC_Q,    KC_H,    KC_O,    KC_U,    KC_X,            KC_G,    KC_C,    KC_M,    KC_R,    KC_V,
    KC_Y,    BEAK_I,  BEAK_E,  BEAK_A,  KC_DOT,          KC_D,    BEAK_S,  BEAK_T,  BEAK_N,  KC_B,
    KC_J,    KC_SLSH, KC_COMM, KC_K,    KC_QUOT,         KC_W,    KC_F,    KC_L,    KC_P,    KC_Z,
                                    KC_LSFT, KC_SPC,  RAISE,   LOWER
  ),

  [_LOWER] = LAYOUT(
    _______, _______, KC_SCLN, KC_GRV,  KC_LPRN,         KC_RPRN, CTRL_D,  CTRL_U,  _______, KC_ESC,
    KC_DEL,  KC_ESC,  KC_TAB,  KC_ENT,  KC_SCLN,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
    _______, _______, KC_BSLS, KC_TILD, KC_LBRC,         KC_RBRC, KC_PGDN, KC_PGUP, _______, KC_ENT,
                                    _______, KC_BSPC, _______, _______
  ),

  [_RAISE] = LAYOUT(
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU,         KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC,
    _______, NO_AE,   NO_OE,   NO_AA,   KC_BRID,         KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS,
    _______, KC_MRWD, KC_MPLY, KC_MFFD, _______,         KC_EQL,  KC_7,    KC_8,    KC_9,    KC_ENT,
                                    _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_INS,          _______, COLEMAK, BEAKL,   _______, _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   QK_BOOT,         _______, _______, _______, _______, _______,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  DEBUG,           _______, _______, _______, _______, _______,
                                    _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    // [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
