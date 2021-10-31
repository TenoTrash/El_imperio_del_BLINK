#include <avr/wdt.h>                                     // Watchdog timer lib
boolean ledState = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  cli();
  WDTCSR = (1 << WDCE) | (1 << WDE);
  WDTCSR = (1 << WDIE) | (1 << WDP2) | (1 << WDP1);                     //1s
  sei();                                                      //Prender interrupciones
}

void loop() {

}

ISR(WDT_vect) {                                    // Watchdog vector
  if (ledState) {
    ledState = false;
  } else {
    ledState = true;
  }
  digitalWrite(LED_BUILTIN, ledState);
}
