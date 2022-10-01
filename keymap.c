#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    M0,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, M0, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LSFT(KC_SCLN), KC_MINS, KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL, KC_DOWN, KC_UP, KC_LALT, KC_LCTL, KC_SPC, LSFT_T(KC_LNG2), LSFT_T(KC_LNG1), MO(1), LT(2,KC_ENT), KC_LALT, KC_LEFT, KC_RGHT),

    [_LAYER1] = LAYOUT(KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_DQUO, KC_QUOT, KC_GRV, KC_TILD, KC_TRNS, KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_AMPR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_TRNS, KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_LAYER2] = LAYOUT(RGB_TOG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAI, RGB_SAD),

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M0:
      if (record->event.pressed) {
        register_code(KC_LNG2);
        register_code(KC_ESC);
      } else {
        unregister_code(KC_LNG2);
        unregister_code(KC_ESC);
      }
      return false;
      break;
  }
  return true;
}
