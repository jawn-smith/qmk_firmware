/* Check on proper usage of MT and LT.
   What should happen is if you tap the Fn key you get an exclamation point
   If you tap the Num key you should get an equals sign
   If either one is held they take you to a new layer
   
   Set up macros over shift keys for custom keys 
  
   Make sure that switching between layers is working correctly
*/

#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _SYMBOLS 2
#define _FN 3
#define _NUMPAD 1
#define _MACROS 4
#define _CAPS 7
#define _CAPS2 8
#define _RCAPS 9

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_SPFN LT(_FN,KC_PERC)
#define KC_SPCT MT(MOD_LCTL, LSFT(KC_1))
#define KC_SPLT MT(MOD_LALT, LSFT(KC_7))
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_LSMC LT(_CAPS, LSFT(KC_9))
#define KC_RSMC LT(_RCAPS, LSFT(KC_0))
#define KC_RST1 LT(5, KC_DEL)
#define KC_RST2 MO(6)
#define KC_GLPK M(0)
#define KC_JERY M(1)
#define KC_IMGR M(2)
#define KC_INCL M(3)
#define KC_EML M(4)
#define KC_PULL M(5)
#define KC_PUSH M(6)
#define KC_SPCS M(7)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_LOCK LGUI(KC_L)
#define KC_DVRK TO(_DVORAK)
#define KC_CPLK TO(_CAPS2)

#define KC_CAPA LSFT(KC_A)
#define KC_CAPB LSFT(KC_B)
#define KC_CAPC LSFT(KC_C)
#define KC_CAPD LSFT(KC_D)
#define KC_CAPE LSFT(KC_E)
#define KC_CAPF LSFT(KC_F)
#define KC_CAPG LSFT(KC_G)
#define KC_CAPH LSFT(KC_H)
#define KC_CAPI LSFT(KC_I)
#define KC_CAPJ LSFT(KC_J)
#define KC_CAPK LSFT(KC_K)
#define KC_CAPL LSFT(KC_L)
#define KC_CAPM LSFT(KC_M)
#define KC_CAPN LSFT(KC_N)
#define KC_CAPO LSFT(KC_O)
#define KC_CAPP LSFT(KC_P)
#define KC_CAPQ LSFT(KC_Q)
#define KC_CAPR LSFT(KC_R)
#define KC_CPS LSFT(KC_S)
#define KC_CAPT LSFT(KC_T)
#define KC_CAPU LSFT(KC_U)
#define KC_CAPV LSFT(KC_V)
#define KC_CAPW LSFT(KC_W)
#define KC_CAPX LSFT(KC_X)
#define KC_CAPY LSFT(KC_Y)
#define KC_CAPZ LSFT(KC_Z)

#define KC_RAPA RSFT(KC_A)
#define KC_RAPB RSFT(KC_B)
#define KC_RAPC RSFT(KC_C)
#define KC_RAPD RSFT(KC_D)
#define KC_RAPE RSFT(KC_E)
#define KC_RAPF RSFT(KC_F)
#define KC_RAPG RSFT(KC_G)
#define KC_RAPH RSFT(KC_H)
#define KC_RAPI RSFT(KC_I)
#define KC_RAPJ RSFT(KC_J)
#define KC_RAPK RSFT(KC_K)
#define KC_RAPL RSFT(KC_L)
#define KC_RAPM RSFT(KC_M)
#define KC_RAPN RSFT(KC_N)
#define KC_RAPO RSFT(KC_O)
#define KC_RAPP RSFT(KC_P)
#define KC_RAPQ RSFT(KC_Q)
#define KC_RAPR RSFT(KC_R)
#define KC_RPS  RSFT(KC_S)
#define KC_RAPT RSFT(KC_T)
#define KC_RAPU RSFT(KC_U)
#define KC_RAPV RSFT(KC_V)
#define KC_RAPW RSFT(KC_W)
#define KC_RAPX RSFT(KC_X)
#define KC_RAPY RSFT(KC_Y)
#define KC_RAPZ RSFT(KC_Z)

  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     MESC,QUOT,COMM,DOT , P  , Y  ,      F  , G  , C  , R  , L  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  , ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSMC,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  ,RSMC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SPCT,SPFN,SPLT,UNDS,NMPD,SLSH,     SPC ,SYMB,ASTR,EQL ,LBRC,RBRC
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,  7 ,  8 ,  9 ,MINS,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  4 ,  5 ,  6 ,PLUS, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,         ,  1 ,  2 ,  3 ,ASTR, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     SPC ,  0 ,  0 , DOT,SLSH, ENT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,     TILD,EQL ,UNDS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F7 , F8 , F9 , F10, F11, F12,     GRV ,PLUS,MINS,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LGUI,    ,    ,    ,    ,    ,     SPC ,    ,    ,    ,    ,    
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
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,PULL,PUSH,    ,    ,         ,GLPK,    ,    ,IMGR,RST1,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,EML ,    ,INCL,     CAD ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,JERY,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     RST1,    ,    ,    ,    ,LOCK,     SPCS,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [5] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     RST2,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [6] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET \
  ),

  [_CAPS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC ,DQUO,LABK,RABK,CAPP,CAPY,     CAPF,CAPG,CAPC,CAPR,CAPL,DEL ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB ,CAPA,CAPO,CAPE,CAPU,CAPI,     CAPD,CAPH,CAPT,CAPN,CPS ,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,COLN,CAPQ,CAPJ,CAPK,CAPX,     CAPB,CAPM,CAPW,CAPV,CAPZ,CPLK,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,MINS,    ,QUES,     SPC ,    ,HASH,PIPE,LCBR,RCBR
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_CAPS2] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC ,DQUO,LABK,RABK,CAPP,CAPY,     CAPF,CAPG,CAPC,CAPR,CAPL,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB ,CAPA,CAPO,CAPE,CAPU,CAPI,     CAPD,CAPH,CAPT,CAPN,CPS ,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     DVRK,COLN,CAPQ,CAPJ,CAPK,CAPX,     CAPB,CAPM,CAPW,CAPV,CAPZ,DVRK,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,UNDS,MINS,QUES,     SPC ,    ,HASH,PIPE,LCBR,RCBR
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_RCAPS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC ,DQUO,LABK,RABK,RAPP,RAPY,     RAPF,RAPG,RAPC,RAPR,RAPL,DEL ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB ,RAPA,RAPO,RAPE,RAPU,RAPI,     RAPD,RAPH,RAPT,RAPN,RPS ,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     CPLK,COLN,RAPQ,RAPJ,RAPK,RAPX,     RAPB,RAPM,RAPW,RAPV,RAPZ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,MINS,    ,QUES,     SPC ,    ,HASH,PIPE,LCBR,RCBR
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
        SEND_STRING("http://imgur.com/a/zu0bN");
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
  }
  return MACRO_NONE;
};
