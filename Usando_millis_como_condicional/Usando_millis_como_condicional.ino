void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if ((millis() / 1000) % 2)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
