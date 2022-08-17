#include QMK_KEYBOARD_H


#define QWERTY 0
#define LOWER 1
#define RAISE 2
#define NUM 3

// Tap Dance Declarations
enum {
    TD_COPY,
    TD_PASTE,
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap once for ctrl+c, twice for ctrl+shift+c
    [TD_COPY] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(LSFT(KC_C))),
    // tap once for ctrl+v, twice for ctrl+shift+v
    [TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_V), LCTL(LSFT(KC_V))),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_6x6(
        KC_GRV         , KC_1         , KC_2   , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7  , KC_8   , KC_9   ,  KC_0  , KC_MINS,
        LSFT_T(KC_TAB) , KC_Q         , KC_W   , KC_E   , KC_R   , KC_T   ,                    KC_Y   , KC_U  , KC_I   , KC_O   ,  KC_P  , KC_EQL ,
        LCTL_T(KC_CAPS), KC_A         , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        LCTL(KC_LSFT)  , KC_Z         , KC_X   , KC_C   , KC_V   , KC_B   ,                    KC_N   , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
        KC_F12         , RALT(KC_RWIN), KC_RALT, KC_LEFT, KC_RGHT, _______,                    _______, KC_UP , KC_DOWN, KC_LBRC, KC_RBRC, KC_F8,
                                       KC_LWIN, KC_LSFT, _______,                              KC_DEL, KC_ENT, KC_RALT,
                                                       TG(RAISE),                              TG(NUM),
                                                       KC_SPC,                                 RSFT_T(KC_BSPC),
                                                       MO(LOWER),                              KC_RCTL
    ),
    [LOWER] = LAYOUT_6x6(
        LCTL(KC_GRV), KC_F1        , KC_F2           , KC_F3           , KC_F4           , KC_F5        ,        KC_F6  , KC_F7  , KC_F8    , KC_F9   , KC_F10 , KC_F11,
        KC_BSPC     , RALT(KC_F4)  , LCTL(KC_W)      , LCTL(KC_S)      , KC_PSCR         , _______      ,        _______, _______, _______  , _______ , _______, KC_F12,
        KC_ENT      , LCTL(KC_A)   , KC_RALT         , KC_LSFT         , KC_RCTL         , LCTL(KC_SLSH),        KC_LEFT, KC_DOWN, KC_UP    , KC_RIGHT, _______, _______,
        _______     , LCTL(KC_Z)   , LCTL(KC_X)      , LCTL(KC_C)      , LCTL(KC_V)      , LCTL(KC_Y)   ,        _______, KC_PGUP, KC_PGDN  , _______ , _______, KC_LALT,
        KC_MUTE     , KC_VOLD      , KC_VOLU         , KC_UP           , KC_DOWN         , _______      ,        _______, KC_HOME, KC_END   , _______ , _______, _______,
                                     _______, _______, _______,                                                  _______, _______, _______,
                                                       _______,                                                  _______,
                                                       _______,                                                  _______,
                                                       _______,                                                  LWIN(KC_SPC)
    ),
    [RAISE] = LAYOUT_6x6(
        RESET  , _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, KC_MS_U, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_WH_U, KC_WH_D, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
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
                                                     _______,                            _______, 
                                                     KC_P0,                              KC_P0
    ),
};