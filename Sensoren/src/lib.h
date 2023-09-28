#include "Arduino_SensorKit.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#define LED 6
#define BUTTON 4
#define POTI A0
#define BUZZER 5
#define LIGHT_SENSOR A3
#define SOUND_SENSOR A2


// Init oled display
Adafruit_SSD1306 display(128, 64, &Wire, -1);
