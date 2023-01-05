#include QMK_KEYBOARD_H

// Mod-Taps
#define MT_LCTL_ESC    LCTL_T(KC_ESC)
#define MT_LOWER_BSPC  LT(_LOWER, KC_BSPC)
#define MT_NAV_SPC     LT(_NAV, KC_SPC)
#define MT_RAISE_ENT   LT(_RAISE, KC_ENT)
#define MT_GUI_DOWN    RGUI_T(KC_DOWN)
#define MT_RCTL_UP     RCTL_T(KC_UP)

enum iris_layers {
  _QWERTY,
  _NAV,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // TODO:
  // - Change KC_LGUI to TD_LGUIALT
  // - Reconsider KC_HOME, KC_END replacements
  [_QWERTY] = LAYOUT(
     KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
     KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     MT_LCTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                 KC_LGUI, MT_LOWER_BSPC,  MT_NAV_SPC,              MT_NAV_SPC,  MT_RAISE_ENT,   KC_LALT
  ),

  [_NAV] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
     _______, _______, _______, KC_BRIU, KC_BRID, _______,                                _______, KC_VOLD, KC_VOLU, _______, KC_PSCR, _______,
     _______, _______, KC_END,  KC_PGUP, KC_PGDN, KC_HOME,                                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                        _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
     _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,                                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                        KC_BTN1, KC_BTN2, KC_BTN3
  ),

  [_LOWER] = LAYOUT(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                KC_CIRC, KC_AMPR,   KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                KC_CIRC, KC_AMPR,   KC_ASTR,   KC_LPRN, KC_RPRN, KC_DEL,
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                  KC_F6,   KC_UNDS,   KC_PLUS,   KC_LCBR, KC_RCBR, KC_PIPE,
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,              _______, KC_F12,  S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END,  _______,
                                    _______, _______, _______,                        _______, _______, _______

//   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
//   QK_BOOT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//   KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
//   BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
//                                  _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
  ),

  [_RAISE] = LAYOUT(
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                  KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,              _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
                                    _______, _______, _______,                        _______, _______, _______

//   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//   RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
//   KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
//                                  _______, _______, _______,                   _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
     _______, QK_BOOT, DB_TOGG, _______, _______, _______,                                _______, _______, _______, _______, _______, KC_DEL,
     _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM,                                AG_SWAP, _______, _______, _______, _______, _______,
     _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON, _______,                _______, MI_OFF,  _______, _______, _______, _______, _______,
                                    _______, _______, _______,                        _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
