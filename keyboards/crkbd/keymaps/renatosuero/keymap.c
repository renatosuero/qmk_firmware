#include QMK_KEYBOARD_H
#include <stdio.h>

// Tap Dance Declarations
enum {
	TD_MINUS_EQUAL = 0,
	TD_LGUI_SYMBOL = 1,
	TD_ESC_GRV = 2,
    TD_LAYER1 = 3,
    TD_LAYER2 = 4
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MINUS_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQL),
};

// In Layer declaration, add tap dance item in place of a key code
const uint16_t kc_min = TD(TD_MINUS_EQUAL);
const uint16_t kc_com = TD(TD_LGUI_SYMBOL);


const uint16_t kc_lalt = MT(MOD_LALT, KC_GRV);

const uint16_t kc_rsft = MT(MOD_RSFT, KC_QUOTE);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    kc_lalt,    KC_Q,    KC_W,    KC_E,    KC_R, KC_T, 				            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RALT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F, KC_G, 				            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, kc_rsft,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V, KC_B, 				            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, kc_min,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LT(3,KC_ESC), KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, LT(2,KC_TAB) 
                                    //`--------------------------'  `--------------------------'
),

[1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    kc_lalt,    KC_Q,    KC_W,    KC_E,    KC_R, KC_T, 				            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RALT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F, KC_G, 				            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, kc_rsft,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V, KC_B, 				            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, kc_min,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(3), KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, MO(2) 
                                        //`--------------------------'  `--------------------------'
),

[2] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
     kc_lalt, KC_1,    KC_2,    KC_3,    KC_4, KC_5, 				            KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_RALT,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(1), 		                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, kc_rsft,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		                XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, KC_SLSH, kc_min,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, MO(2) 
				                    //`--------------------------'  `--------------------------'
),

[3] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
     kc_lalt, KC_EXLM, KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RALT,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, 		               KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX, XXXXXXX, kc_rsft,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, kc_min,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(3), KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, XXXXXXX 
				                //`--------------------------'  `--------------------------'

)};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_0;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#    define L_COLEMAK 0
#    define L_QWERTY 2
#    define L_NUMBER 4
#    define L_SYMBOL 8
#    define L_ADJUST 16

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_COLEMAK:
            oled_write_ln_P(PSTR(">>>> DEFAULT <<<<"), false);
    	    oled_write_ln_P(PSTR(""),false);
     	    oled_write_ln_P(PSTR(""),false);
            break;
        case L_QWERTY:
            oled_write_ln_P(PSTR(">>>> COLEMAK <<<<"), false);
            oled_write_ln_P(PSTR(""),false);
            oled_write_ln_P(PSTR(""),false);
            break;
        case L_NUMBER:
            oled_write_ln_P(PSTR(">>>> NUMBER <<<<"), false);
    	    oled_write_ln_P(PSTR("\x95\x96"),false);
     	    oled_write_ln_P(PSTR("\xB5\xB6"),false);
            break;
        case L_SYMBOL:
            oled_write_ln_P(PSTR(">>>>SYMBOL<<<<"), false);
    	    oled_write_ln_P(PSTR("\x95\x96"),false);
     	    oled_write_ln_P(PSTR("\xB5\xB6"),false);
            break;
        case L_ADJUST:
        case L_ADJUST | L_SYMBOL:
        case L_ADJUST | L_NUMBER:
        case L_ADJUST | L_SYMBOL | L_NUMBER | L_COLEMAK:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif  // OLED_ENABLE
