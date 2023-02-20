
/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

//homerowns default layer
#define hr_lctl MT(MOD_LCTL,KC_F) 
#define hr_rctl MT(MOD_RCTL,KC_J) 

#define hr_lsft MT(MOD_LSFT,KC_D) 
#define hr_rsft MT(MOD_RSFT,KC_K) 

#define hr_lalt MT(MOD_RALT,KC_S) 
#define hr_ralt MT(MOD_RALT,KC_L) 

// homewows layer 1
#define hr1_rctl MT(MOD_RCTL,KC_DOWN) 
#define hr1_rsft MT(MOD_RSFT,KC_UP) 
#define hr1_ralt MT(MOD_RALT,KC_RIGHT) 


// others
#define kc_layer1_tab LT(1,KC_TAB) 
#define kc_layer2_esc LT(2,KC_ESC) 
#define kc_layer3_bsp LT(3,KC_BSPC) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R, KC_T, 				                KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		XXXXXXX,    KC_A,   hr_lalt,hr_lsft,hr_lctl, KC_G, 				               KC_H,   hr_rctl, hr_rsft, hr_ralt, KC_SCLN, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V, KC_B, 				               KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											 kc_layer2_esc, kc_layer3_bsp, KC_LGUI,      KC_ENT,  KC_SPC, kc_layer1_tab 
										//`--------------------------'  `--------------------------'
	),

	[1] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		 XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4, KC_5, 				            KC_6,    KC_7,    KC_8,    KC_9,   KC_0, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, KC_GRV, KC_LALT, KC_LSFT,KC_LCTL, XXXXXXX, 		                KC_LEFT, hr1_rctl, hr1_rsft, hr1_ralt, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 		                XXXXXXX, KC_RCTL, KC_DOT, KC_SLSH, XXXXXXX, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											 XXXXXXX, KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, kc_layer1_tab 
										//`--------------------------'  `--------------------------'
	),

	[2] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		 XXXXXXX, KC_EXLM, KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQL, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, KC_GRV, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, 		               XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_QUOTE,XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,					   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											 kc_layer2_esc, KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, XXXXXXX
									//`--------------------------'  `--------------------------'
	),

	[3] = LAYOUT_split_3x6_3(
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		 XXXXXXX, KC_EXLM, KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQL, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, 		               KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX, KC_DELETE,XXXXXXX,
	//|-----j--+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3,					   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, XXXXXXX,
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											 kc_layer2_esc, KC_BSPC, KC_LGUI,      KC_ENT,  KC_SPC, XXXXXXX 
									//`--------------------------'  `--------------------------'
	),

};

