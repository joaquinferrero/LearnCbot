//
// LearnCbot.h
// LearnCbot definitions for Arduino
//
// Joaquin Ferrero (aka explorer)
//
// 2015-04-24T03:40:39+0200	: Primera versión
// 2015-04-24T11:36:13+0200	: Corregir nombres
// 2015-04-25T02:17:58+0200	: Reardenar secciones
//

#ifndef LearnCbot_h
#define LearnCbot_h

#include <Arduino.h>

// Pousspoir - Buttons - Botones - Botãos -------------------------------------

// Pattes - Pins - Pines
#define Pous1Pin		PIN2
#define Pous2Pin		PIN3

// Actions
#define Pous(x)			digitalRead(x)

// Français
#define Pous1			Pous(Pous1Pin)
#define Pous1On			(Pous1 == LOW )
#define Pous1Off		(Pous1 == HIGH)
#define Pous2			Pous(Pous2Pin)
#define Pous2On			(Pous2 == LOW )
#define Pous2Off		(Pous2 == HIGH)

// English
#define Button1			Pous1
#define Button1Pin		Pous1Pin
#define Button1On		Pous1On
#define Button1Off		Pous1Off
#define Button2			Pous2
#define Button2Pin		Pous2Pin
#define Button2On		Pous2On
#define Button2Off		Pous2Off

// Español
#define Boton1			Pous1
#define Boton1Pin		Pous1Pin
#define Boton1On		Pous1On
#define Boton1Off		Pous1Off
#define Boton2			Pous2
#define Boton2Pin		Pous2Pin
#define Boton2On		Pous2On
#define Boton2Off		Pous2Off

// Português
#define Botao1			Pous1
#define Botao1Pin		Pous1Pin
#define Botao1On		Pous1On
#define Botao1Off		Pous1Off
#define Botao2			Pous2
#define Botao2Pin		Pous2Pin
#define Botao2On		Pous2On
#define Botao2Off		Pous2Off

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

// Actions
#define Led(x)			digitalRead (x)
#define LedOn(x)		digitalWrite(x, HIGH)
#define LedOff(x)		digitalWrite(x, LOW )
#define LedToggle(x)		digitalWrite(x, !Led(x))

#define Led1On			LedOn    (Led1Pin)
#define Led1Off			LedOff   (Led1Pin)
#define Led1Toggle		LedToggle(Led1Pin)
#define Led2On			LedOn    (Led2Pin)
#define Led2Off			LedOff   (Led2Pin)
#define Led2Toggle		LedToggle(Led2Pin)
#define Led3On			LedOn    (Led3Pin)
#define Led3Off			LedOff   (Led3Pin)
#define Led3Toggle		LedToggle(Led3Pin)
#define Led4On			LedOn    (Led4Pin)
#define Led4Off			LedOff   (Led4Pin)
#define Led4Toggle		LedToggle(Led4Pin)

// LED in carte
#define LedCartePin		LED_BUILTIN
#define LedCarte		Led      (LedCartePin)
#define LedCarteOn		LedOn    (LedCartePin)
#define LedCarteOff		LedOff   (LedCartePin)
#define LedCarteToggle		LedToggle(LedCartePin)

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



void LCbot_Setup () {				// Define I/O
    pinMode (HPPin, OUTPUT);

    pinMode (Pous1Pin, INPUT);
    pinMode (Pous2Pin, INPUT);

    pinMode (Led1Pin, OUTPUT);
    pinMode (Led2Pin, OUTPUT);
    pinMode (Led3Pin, OUTPUT);
    pinMode (Led4Pin, OUTPUT);

    for (int i = 0; i <= 4; i++) {
	LedOff(i);
    }
}

void LCbot_ShowStart () {			// Show LearnCbot is ready
    pinMode (LedCartePin, OUTPUT);

    delay(200);
    LedCarteOn; delay(500);

    for (int i = 0; i < 3; i++) {
	LedCarteOff;	delay(100);
	LedCarteOn;	delay(100);
    }

    LedCarteOff; delay(200);
}

// LCbot OOP
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
