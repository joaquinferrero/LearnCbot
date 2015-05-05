
#include "LearnCbot.h"

LCbot lcbot;

volatile int lapso;

void setup() {
    lcbot.ShowStart();

    attachInterrupt(0,tope,FALLING);
    attachInterrupt(1,zero,FALLING);
}

void loop() {
    for (lapso = 200; lapso > 0; lapso--) {
	clignoter(lapso);
    }

    for (lapso = 0; lapso < 200; lapso++) {
	clignoter(lapso);
    }
}

void clignoter(int lapso) {
    for (int i = Led1_pin; i <= Led4_pin; i++) {

	lcbot.set_on(i);

	delay(lapso);

	lcbot.set_off(i);

	delay(lapso);
    }
}

void tope() {
    lapso = 200;
    attandre();
}

void zero() {
    lapso = 0;
    attandre();
}

void attandre() {
    for (int i = 0; i < 5000; i++) {
	;
    }
}
