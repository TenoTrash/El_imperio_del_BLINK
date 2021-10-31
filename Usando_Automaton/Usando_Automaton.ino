#include <Automaton.h>
#include "Atm_blink.h"

Atm_blink led;

void setup() {
  led.begin( 13, 1000 );        // Setup a blink machine on pin 4
  led.trigger( led.EVT_ON );  // Turn it on
}

void loop() {
  automaton.run();
}
