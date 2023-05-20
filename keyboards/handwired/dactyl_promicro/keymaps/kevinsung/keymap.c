#include QMK_KEYBOARD_H

#define QWERTY 0
#define LOWER 1
#define RAISE 2
#define NUM 3

enum combo_events {
  ZX_MOVE_WINDOW_MONITOR_LEFT,
  CV_MOVE_WINDOW_MONITOR_RIGHT
};

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_MOVE_WINDOW_MONITOR_LEFT] = COMBO_ACTION(zx_combo),
  [CV_MOVE_WINDOW_MONITOR_RIGHT] = COMBO_ACTION(cv_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZX_MOVE_WINDOW_MONITOR_LEFT:
      if (pressed) {
        tap_code16(LSFT(LWIN(KC_LEFT)));
      }
      break;
    case CV_MOVE_WINDOW_MONITOR_RIGHT:
      if (pressed) {
        tap_code16(LSFT(LWIN(KC_RGHT)));
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_6x6(
        KC_GRV        , KC_1          , KC_2          , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7  , KC_8   , KC_9   ,  KC_0  , KC_MINS,
        KC_TAB        , KC_Q          , KC_W          , KC_E   , KC_R   , KC_T   ,                    KC_Y   , KC_U  , KC_I   , KC_O   ,  KC_P  , KC_EQL ,
        C_S_T(KC_CAPS), KC_A          , KC_S          , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT , KC_Z          , KC_X          , KC_C   , KC_V   , KC_B   ,                    KC_N   , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
        KC_F12        , KC_LCTL       , KC_LALT       , KC_LEFT, KC_RGHT, _______,                    _______, KC_UP , KC_DOWN, KC_LBRC, KC_RBRC, RCTL_T(KC_F8),
                                                          KC_LWIN, LALT(KC_RWIN), KC_F11,                    KC_DEL, KC_ENT, KC_RALT,
                                                                        TG(RAISE),                    TG(NUM),
                                                                           KC_SPC,                    KC_BSPC,
                                                                        MO(LOWER),                    KC_RSFT
    ),
    [LOWER] = LAYOUT_6x6(
        LCTL(KC_GRV) , KC_F1      , KC_F2     , KC_F3     , KC_F4     , KC_F5     ,        KC_F6     , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
        RALT(KC_F4)  , LCTL(KC_Q) , LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T),        LCTL(KC_Y), KC_7   , KC_8   , KC_9   , KC_PSCR, KC_F12,
        KC_ENT       , LCTL(KC_A) , LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G),        LCTL(KC_H), KC_4   , KC_5   , KC_6   , KC_BSPC, _______,
        LCTL(KC_SLSH), LCTL(KC_Z) , LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B),        LCTL(KC_N), KC_1   , KC_2   , KC_3   , KC_DOT , _______,
        _______      , _______    , _______   , KC_PGUP   , KC_PGDN   , _______   ,        _______, KC_HOME, KC_END , KC_VOLD, KC_VOLU, KC_MUTE,
                                           _______, _______, _______,                      _______, LWIN(KC_SPC), _______,
                                                             _______,                      _______,
                                                             _______,                      KC_0,
                                                             _______,                      LCTL(KC_RSFT)
    ),
    [RAISE] = LAYOUT_6x6(
        RESET  , _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                            _______, _______, KC_MS_U, _______, _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                            _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,                            _______, KC_WH_U, KC_WH_D, _______, _______, _______,
        _______, _______, _______, KC_UP  , KC_DOWN, _______,                            _______, _______, _______, KC_BRID, KC_BRIU, _______,
                                   _______, _______, _______,                            _______, KC_BTN1, _______, 
                                                     _______,                            _______,
                                                     _______,                            KC_BTN3, 
                                                     _______,                            KC_BTN2
    ),
    [NUM] = LAYOUT_6x6(
        _______, _______, _______, _______, _______, _______,                            _______, KC_NUM , KC_PSLS, KC_PAST, KC_PEQL, _______,
        _______, _______, KC_P7  , KC_P8  , KC_P9  , _______,                            _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, _______, KC_P4  , KC_P5  , KC_P6  , _______,                            _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, _______, KC_P1  , KC_P2  , KC_P3  , _______,                            _______, KC_P1  , KC_P2  , KC_P3  , KC_PDOT, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,                            _______, _______, _______, 
                                                     _______,                            _______,
                                                     KC_P0,                              KC_P0,
                                                     _______,                            _______
    ),
};