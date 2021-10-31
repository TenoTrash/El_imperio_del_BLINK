long contador = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  contador++;
  if (contador == 100000) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (contador == 200000) {
    contador = 0;
    digitalWrite(LED_BUILTIN, LOW);
  }
}
