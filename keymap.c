/*******************************************
 * QMK firmware for a let's split keyboard
 *
 * William Wilson
 * June 16, 2017
 ******************************************/

#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _NUMPAD 1
#define _SYMBOLS 2
#define _FN 3
#define _MACROS 4
#define _QWERTY 5
#define _QNUMPAD 6
#define _QSYMBOLS 7
#define _QFN 8
#define _QMACROS 9

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_QNUM TG(_QNUMPAD)
#define KC_QSYM TG(_QSYMBOLS)
#define KC_QSFN LT(_QFN,KC_MINS)
#define KC_SPFN LT(_FN,KC_MINS)
#define KC_SPCT MT(MOD_LCTL, KC_BSLS)
#define KC_SPLT MT(MOD_LALT, KC_EQL)
#define KC_GBRC MT(MOD_RGUI, KC_RBRC)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_QESC LT(_QMACROS, KC_ESC)
#define KC_GLPK M(0)
#define KC_JERY M(1)
#define KC_IMGR M(2)
#define KC_INCL M(3)
#define KC_EML M(4)
#define KC_PULL M(5)
#define KC_PUSH M(6)
#define KC_SPCS M(7)
#define KC_PSWD M(8)
#define KC_RED M(9)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_LOCK LGUI(KC_L)
#define KC_DVRK TO(_DVORAK)
#define KC_QWRT TO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     MESC,QUOT,COMM,DOT , P  , Y  ,      F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  , ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSPO,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  ,RSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SPCT,SPFN,SPLT,AMPR,NMPD,BSPC,     SPC ,SYMB,ASTR,EXLM,LBRC,GBRC
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,  7 ,  8 ,  9 ,MINS,SLSH,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  4 ,  5 ,  6 ,PLUS, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,         ,  1 ,  2 ,  3 ,ASTR, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,BSPC,     SPC ,  0 ,  0 , DOT,SLSH,RGUI
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,SLSH,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,     TILD,EQL ,UNDS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F7 , F8 , F9 , F10, F11, F12,     GRV ,PLUS,MINS,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    , NO ,BSPC,     SPC ,    ,    ,    ,    ,RGUI
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    , DEL,BSPC,         ,HOME, UP , END, INS,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,LSFT,LCTL, ENT,         ,LEFT,DOWN,RGHT, DEL,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,PGUP,PGDN,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,         ,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,PULL,PUSH,PSWD,    ,         ,GLPK,    ,    ,IMGR,QWRT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,EML ,    ,INCL,     CAD ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,JERY,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     SPCS,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     QESC, Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SPCT,QSFN,SPLT,AMPR,QNUM,BSPC,     SPC ,QSYM,ASTR,EXLM,LBRC,GBRC
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QNUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,  7 ,  8 ,  9 ,MINS,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  4 ,  5 ,  6 ,PLUS, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,         ,  1 ,  2 ,  3 ,ASTR, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,BSPC,     SPC ,  0 ,  0 , DOT,SLSH,RGUI
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QSYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,     TILD,EQL ,UNDS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F7 , F8 , F9 , F10, F11, F12,     GRV ,PLUS,MINS,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    , NO ,BSPC,     SPC ,    ,    ,    ,    ,RGUI
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QFN] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    , DEL,BSPC,         ,HOME, UP , END, INS,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,LSFT,LCTL, ENT,         ,LEFT,DOWN,RGHT, DEL,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,PGUP,PGDN,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,         ,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QMACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,EML ,    ,    ,         ,    ,INCL,    ,PSWD,DVRK,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,GLPK,         ,JERY,    ,IMGR,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,PULL,PUSH,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     SPCS,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ) 
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
                SEND_STRING("GlenPickle");
        return false; // This is false because it has to return something.
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("My friend Louisa got straight A's all the way from kindergarten to her PhD. One day while we were out biking in Europe we ran into John Nash knife fighting with Sifu. I was busy fighting a student of mine with my Aikido, or else I would have hypnotized both John Nash and Sifu. I HATE A WHITE SAUCE.");
        return false;
      }
      break;
    case 2:
      if (record->event.pressed) {
        SEND_STRING("http://imgur.com/gallery/PRDJm");
        return false;
      }
      break;
    case 3:
      if (record->event.pressed) {
        SEND_STRING("#include<>");
        return false;
      }
      break;
    case 4:
      if (record->event.pressed) {
        SEND_STRING("wilson.r.william@gmail.com");
        return false;
      }
      break;
    case 5:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        return MACRO( T(ENT), END );
      }
      break;
    case 6:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
    case 7:
      if (record->event.pressed){
        SEND_STRING("   ");
        return false;
      }
      break;
    case 8:
      if (record->event.pressed){
        SEND_STRING("asdfASDFasdf12!@");
        return MACRO ( T(ENT), END );
      }
      break;
/*    case 9:
      if (record->event.pressed){
        rgblight_setrgb(0xff,0x00,0x00);
        return false;
      }
      break;*/
  }
  return MACRO_NONE;
};

/*void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {

    case _DVORAK:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0xff,0x00);
      #endif
      break;

    case _NUMPAD:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0x00,0xff);
      #endif
      break;

    case _SYMBOLS:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0x00);
      #endif
      break;

    case _FN:
      #ifdef RGBLIGHT_ENABLE
       rgblight_setrgb(0xff,0xff,0xff);
      #endif
      break;

    case _MACROS:
      #ifdef RGBLIGHT_ENABLE
       rgblight_setrgb(0x00,0xff,0x00);
      #endif
      break;

    case _QWERTY:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0xff);
      #endif
      break;

    case _QNUMPAD:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0x00,0xff);
      #endif
      break;

    case _QSYMBOLS:
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0x00);
      #endif
      break;

    case _QFN:
      #ifdef RGBLIGHT_ENABLE
       rgblight_setrgb(0xff,0xff,0xff);
      #endif
      break;

    case _QMACROS:
      #ifdef RGBLIGHT_ENABLE
       rgblight_setrgb(0xff,0x00,0xff);
      #endif
      break;

    default:
      // none
      break;
    }

};*/
