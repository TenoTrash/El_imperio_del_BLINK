boolean ledState = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  TCCR1A = 0;                      //Reset Timer1

  bitClear(TCCR1B, WGM13);
  bitSet(TCCR1B, WGM12);

  bitSet(TCCR1B, CS12);            //Prescaler to 1024
  bitClear(TCCR1B, CS11);
  bitSet(TCCR1B, CS10);

  TCNT1 = 0;
  OCR1A = 15625;   //1s
  //OCR1A = 31250;   //2s

  bitSet(TIMSK1, OCIE1A);
  sei();                  // habilitar interrupciones
}

void loop() {
  
}

ISR(TIMER1_COMPA_vect)
{
  if (ledState)                
  {
    ledState = false;
  }
  else                         
  {
    ledState = true;
  }
  digitalWrite(LED_BUILTIN, ledState); //Set LED 
}
