#include <Arduino.h>
#include "lib.h"



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello, world!");
  display.display();
}

void loop() {

}
