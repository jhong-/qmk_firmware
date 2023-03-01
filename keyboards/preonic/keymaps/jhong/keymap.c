#include QMK_KEYBOARD_H
#include "muse.h"

// Mod-Taps
#define MT_LCTL_ESC    LCTL_T(KC_ESC)
#define MT_RCTL_QUOT   RCTL_T(KC_QUOT)
#define MT_LALT_LEFT   LALT_T(KC_LEFT)
#define MT_GUI_DOWN    RGUI_T(KC_DOWN)
#define MT_RCTL_UP     RCTL_T(KC_UP)

// Layer-Taps
#define LT_LOWER_BSPC  LT(_LOWER, KC_BSPC)
#define LT_NAV_SPC     LT(_NAV, KC_SPC)
#define LT_RAISE_ENT   LT(_RAISE, KC_ENT)

// Tap Dance Aliases
#define TD_LGUIALT     TD(TD_LGUI_ALT_HOLD)

enum preonic_layers {
  _QWERTY,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  LOWER,
  RAISE,
  BACKLIT
};

enum tapdance_keycodes {
  TD_LGUI_ALT_HOLD,
};

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  td_state_t lgui;
  td_state_t lower;
} td_tap_t;

td_state_t current_dance(qk_tap_dance_state_t *state);

void td_lgui(qk_tap_dance_state_t *state, void *user_data);
void td_lgui(qk_tap_dance_state_t *state, void *user_data);

void td_lower(qk_tap_dance_state_t *state, void *user_data);
void td_lower(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
 * Esc: Hold - Left Ctrl, Tap - Esc
 * Enter: Hold - Right Shift, Tap - Enter
 * Left: Hold - Left Alt, Tap - Left
 * Down: Hold - Right GUI, Tap - Down
 * Up: Hold - Right Ctrl, Tap - Up
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,      KC_1,    KC_2,    KC_3,       KC_4,          KC_5,       KC_6,       KC_7,          KC_8,         KC_9,        KC_0,       KC_DEL,
  KC_TAB,      KC_Q,    KC_W,    KC_E,       KC_R,          KC_T,       KC_Y,       KC_U,          KC_I,         KC_O,        KC_P,       KC_BSPC,
  MT_LCTL_ESC, KC_A,    KC_S,    KC_D,       KC_F,          KC_G,       KC_H,       KC_J,          KC_K,         KC_L,        KC_SCLN,    MT_RCTL_QUOT,
  KC_LSFT,     KC_Z,    KC_X,    KC_C,       KC_V,          KC_B,       KC_N,       KC_M,          KC_COMM,      KC_DOT,      KC_SLSH,    KC_RSFT,
  BACKLIT,     KC_RCTL, KC_LALT, TD_LGUIALT, LT_LOWER_BSPC, LT_NAV_SPC, LT_NAV_SPC, LT_RAISE_ENT,  MT_LALT_LEFT, MT_GUI_DOWN, MT_RCTL_UP, KC_RGHT
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | BRIU | BRID |      |      | Vol- | Vol+ |      | PSCR |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | End  | Pg Up| Pg Dn| Home | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |Insert|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_BRIU, KC_BRID, _______, _______, KC_VOLD, KC_VOLU, _______, KC_PSCR, _______,
  _______, _______, KC_END,  KC_PGUP, KC_PGDN, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_INS , _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ACL0 | Reset| Debug|      |      |RGB_T |Aud cy|Aud on|AudOff|AGnorm|AGswap|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ACL1 |      |M_CLK |R_CLK |L_CLK |RGB_M | MS_L | MS_D | MS_U | MS_R |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ACL2 |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_ACL0, QK_BOOT, DB_TOGG, _______, _______, RGB_TOG, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,
  KC_ACL1, _______, KC_BTN2, KC_BTN2, KC_BTN1, RGB_MOD, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  KC_ACL2, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool handle_shift_backspace_to_delete(keyrecord_t *record)
{
  // Initialize a boolean variable that keeps track
  // of the delete key status: registered or not?
  static bool delkey_registered;

  if (record->event.pressed) {
    // Detect the activation of either shift keys
    if (mod_state & MOD_MASK_SHIFT) {
      // First temporarily canceling both shifts so that
      // shift isn't applied to the KC_DEL keycode
      del_mods(MOD_MASK_SHIFT);
      register_code(KC_DEL);
      // Update the boolean variable to reflect the status of KC_DEL
      delkey_registered = true;
      // Reapplying modifier state so that the held shift key(s)
      // still work even after having tapped the Backspace/Delete key.
      set_mods(mod_state);
      return false;
    }
  }
  // On release of KC_BSPC
  else {
    // In case KC_DEL is still being sent even after the release of KC_BSPC
    if (delkey_registered) {
      unregister_code(KC_DEL);
      delkey_registered = false;
      return false;
    }
  }
  // Let QMK process the KC_BSPC keycode as usual outside of shift
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();

  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LT_LOWER_BSPC:
          if (record->tap.count)
          {
            return handle_shift_backspace_to_delete(record);
          }
          // Fall-through: Holding for _LOWER
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
        case LT_RAISE_ENT:
          // Tapping for KC_ENT
          if (record->tap.count)
          {
            return true;
          }
          // Fall-through: Holding for _RAISE
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case KC_BSPC:
          return handle_shift_backspace_to_delete(record);
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
  return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
      }
  }
  return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

td_state_t current_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
      return TD_SINGLE_TAP;
    // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
    else
      return TD_SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted || !state->pressed)
      return TD_DOUBLE_TAP;
    else
      return TD_DOUBLE_HOLD;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)
      return TD_TRIPLE_TAP;
    else
      return TD_TRIPLE_HOLD;
  }
  else
    return TD_UNKNOWN;
}

// Global Tap Dance State
static td_tap_t tap_states = {
  .lgui = TD_NONE,
  .lower = TD_NONE
};

void lgui_finished(qk_tap_dance_state_t *state, void *user_data) {
  tap_states.lgui = current_dance(state);
  switch (tap_states.lgui) {
    case TD_SINGLE_TAP:
    case TD_SINGLE_HOLD:
      register_code(KC_LGUI);
      break;
    case TD_DOUBLE_TAP:
    case TD_DOUBLE_HOLD:
      unregister_code(KC_LGUI);
      register_code(KC_LALT);
      break;
    default:
      break;
  }
}

void lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_states.lgui) {
    case TD_SINGLE_TAP:
    case TD_SINGLE_HOLD:
      unregister_code(KC_LGUI);
      break;
    case TD_DOUBLE_TAP:
    case TD_DOUBLE_HOLD:
      unregister_code(KC_LALT);
      break;
    default:
      break;
  }
  tap_states.lgui = TD_NONE;
}

// Tap Dance defintions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_ALT_HOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_finished, lgui_reset)
};
