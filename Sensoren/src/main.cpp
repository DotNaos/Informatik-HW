#include <Arduino.h>
#include "lib.h"

volatile bool state = false;

void buttonPressed() {
  state = !state;
  digitalWrite(LED, state);
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, FALLING);
}

void loop() {
  digitalWrite(BUZZER, HIGH);
  delay(30);
}
