//
// LearnCbot.h
// LearnCbot definitions for Arduino
//
// Joaquin Ferrero (aka explorer)
//
// 2015-04-24	: Primera versión
// 2015-04-24	: Corregir nombres
// 2015-04-25	: Reardenar secciones
// 2015-05-02	: Más simple
//

#ifndef LearnCbot_h
#define LearnCbot_h

// (un)define LCbot_CANONICO two versions the code
// LCbot_CANONICO defined: use Arduino API
// LCbot_CANONICO not defined: use port calls directly
#undef LCbot_CANONICO

#include "Arduino.h"

// Pousspoir - Buttons - Botones - Botãos -------------------------------------

// Pattes - Pins - Pines
#define Pous1Pin		PIN2
#define Pous2Pin		PIN3

// Actions
#ifdef LCbot_CANONICO
#define Pous(x)			digitalRead(x)
#else
#define Pous(x)			((PIND & (1<<(x))) != 0)
#endif

// Pousspoir
#define Pous1			Pous(Pous1Pin)
#define Pous1On			(Pous1 == LOW )
#define Pous1Off		(Pous1 == HIGH)
#define Pous2			Pous(Pous2Pin)
#define Pous2On			(Pous2 == LOW )
#define Pous2Off		(Pous2 == HIGH)

// LEDs -----------------------------------------------------------------------

// LED Pattes
#define Led1Pin			PIN4
#define Led2Pin			PIN5
#define Led3Pin			PIN6
#define Led4Pin			PIN7
#define L1			Led1Pin
#define L2			Led2Pin
#define L3			Led3Pin
#define L4			Led4Pin
#define LedRouge1		Led1Pin
#define LedRouge2		Led4Pin
#define LedVert1		Led2Pin
#define LedVert2		Led3Pin

// Actions PORTD
#ifdef  LCbot_CANONICO
#define LedEtat(x)		digitalRead (x)
#define LedOn(x)		digitalWrite(x, HIGH)
#define LedOff(x)		digitalWrite(x, LOW )
#define LedToggle(x)		digitalWrite(x, !LedEtat(x))
#else
#define LedEtat(x)		((PIND & (1<<(x))) != 0)
#define LedOn(x)		(PORTD |=  (1<<(x)))
#define LedOff(x)		(PORTD &= ~(1<<(x)))
#define LedToggle(x)		(PIND = (1<<(x)))
#endif

#define Led1Etat		LedEtat  (Led1Pin)
#define Led1On			LedOn    (Led1Pin)
#define Led1Off			LedOff   (Led1Pin)
#define Led1Toggle		LedToggle(Led1Pin)
#define Led2Etat		LedEtat  (Led2Pin)
#define Led2On			LedOn    (Led2Pin)
#define Led2Off			LedOff   (Led2Pin)
#define Led2Toggle		LedToggle(Led2Pin)
#define Led3Etat		LedEtat  (Led3Pin)
#define Led3On			LedOn    (Led3Pin)
#define Led3Off			LedOff   (Led3Pin)
#define Led3Toggle		LedToggle(Led3Pin)
#define Led4Etat		LedEtat  (Led4Pin)
#define Led4On			LedOn    (Led4Pin)
#define Led4Off			LedOff   (Led4Pin)
#define Led4Toggle		LedToggle(Led4Pin)

// Haut-Parleur
#define HPPin			PIN1
#define HPOn			LedOn    (HPPin)
#define HPOff			LedOff   (HPPin)
#define HPToggle		LedToggle(HPPin)

// Motor
#define MotDArriere		Led1Pin
#define MotDAvance		Led2Pin
#define MotGArriere		Led4Pin
#define MotGAvance		Led3Pin


// Setup ----------------------------------------------------------------------
void LCbot_Setup () {

    // Direction:
    //  0 : INPUT
    //  1 : OUTPUT
    DDRD = 0b11110010 | (DDRD & 0b1);
    //       ^||||||- pinMode (Led4Pin, OUTPUT);
    //        ^|||||- pinMode (Led3Pin, OUTPUT);
    //         ^||||- pinMode (Led2Pin, OUTPUT);
    //          ^|||- pinMode (Led1Pin, OUTPUT);
    //           ^||- pinMode (Pous2Pin, INPUT);
    //            ^|- pinMode (Pous1Pin, INPUT);
    //             ^- pinMode (HPPin, OUTPUT);
}

void LCbot_ShowStart () {			// Show LearnCbot is ready
    pinMode (LED_BUILTIN, OUTPUT);

    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);

    for (int i = 0; i < 3; i++) {		// 3 parpadeos
	digitalWrite(LED_BUILTIN, LOW );	delay(100);
	digitalWrite(LED_BUILTIN, HIGH);	delay(100);
    }

    digitalWrite(LED_BUILTIN, LOW );		// apagar
    delay(200);
}

// LCbot OOP ------------------------------------------------------------------
class LCbot {
    public:
	LCbot();
	void ShowStart();
	void on     (char led);
	void off    (char led);
	void toggle (char led);
};

LCbot::LCbot() {
    LCbot_Setup();
}

void LCbot::ShowStart() {
    LCbot_ShowStart();
}

void LCbot::on(char led) {
    LedOn(led);
}

void LCbot::off(char led) {
    LedOff(led);
}

void LCbot::toggle(char led) {
    LedToggle(led);
}

#endif
