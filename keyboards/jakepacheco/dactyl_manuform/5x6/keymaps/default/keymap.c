// Copyright 2021 david@impstyle.com (@zwnk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _RAISE
};

#define RAISE MO(_RAISE)

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PINK}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    raise_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_set_effect_range(0, 14);
    rgblight_sethsv(HSV_OFF);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_HOME,         KC_END , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_PLUS,         KC_PGUP, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        KC_DEL , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_GRV ,         KC_PGDN, KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                           KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
        KC_LCTL,KC_ESC, KC_LALT,KC_LBRC,                                                          KC_RBRC,KC_RALT,KC_EQL ,KC_RCTL,
                                KC_BSPC,KC_TAB , RAISE ,                           RAISE ,KC_UP  ,KC_RGHT,
                                KC_SPC,KC_LGUI,KC_PSCR,                          KC_LEFT,KC_DOWN,KC_ENT
    ),
    [_RAISE] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,_______,         _______, KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,_______,_______,         _______,KC_NUM , KC_P7 , KC_P8 , KC_P9 ,KC_PPLS,_______,
        _______,_______,_______,_______,_______,_______,_______,         _______,_______, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,_______,_______,_______,_______,_______,                         _______, KC_P1 , KC_P2 , KC_P3 ,KC_SLSH,KC_UNDS,
        _______,_______,_______,_______,                                                           KC_P0 ,_______,_______,_______,
                                _______,_______,_______,                          _______,_______,_______,
                                _______,_______,_______,                          _______,_______,_______
    )
};
