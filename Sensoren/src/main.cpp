#include <Arduino.h>
#include "lib.h"
#include "joystick.h"


void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello, world!");
  display.display();

  analogReadResolution(12);
}

  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(0, 0);
  // display.println(analogRead(joyX));
  // display.println(analogRead(joyY));

  // display.drawCircle(64, 32, analogRead(POTI) / 10, WHITE);

//  Create a Buffer to store the values of the joystick
// The length of the buffer is 10
const int length = 3;
int bufferX[length];
int bufferY[length];
int current = 0;

void loop() {
  // Read the values of the joystick
  // And store them in the buffer
  u_int16_t x = analogRead(joyX);
  u_int16_t y = analogRead(joyY);
  bufferX[0] = x;
  bufferY[0] = y;
  // Shift the values in the buffer
  for (int i = length-1; i > 0; i--) {
    bufferX[i] = bufferX[i - 1];
    bufferY[i] = bufferY[i - 1];
  }



  if (current != 0) {
    current = (current + 1) % length;
    return;
  }

  // Calculate the average of the values in the buffer
  x = 0;
  y = 0;
  for (int i = 0; i < length; i++) {
    x += bufferX[i];
    y += bufferY[i];
  }
  x /= length;
  y /= length;

  // Map the values to a range of 0 - 1
  float x_mapped = x / 4095.0;
  float y_mapped = y / 4095.0;

  // Display a pong ball that moves with the joystick

  display.clearDisplay();
  display.drawCircle(128 - x_mapped * 128, 64 -  y_mapped * 64, 5, WHITE);






  display.display();
}
