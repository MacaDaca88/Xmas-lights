#include <FastLED.h>

// LED strip configuration
#define LED_PIN 6  // Pin connected to the LED strip data line
#define LED_COUNT 2000  // Total number of LEDs (2 strips of 1000 each)
#define LED_BRIGHTNESS 255  // Set the brightness between 0 and 255

// Define Christmas colors
CRGB red(255, 0, 0);
CRGB green(0, 255, 0);
CRGB white(255, 255, 255);

// Declare LED strip
CRGB leds[LED_COUNT];

void setup() {
  // Initialize LED strip
  FastLED.addLeds<WS2812B, LED_PIN>(leds, LED_COUNT);
  FastLED.setBrightness(LED_BRIGHTNESS);
  
  // Seed the random number generator
  randomSeed(analogRead(A0));

  // Initialize the LED strip to an off state
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // Randomly select a color from Christmas colors
  CRGB color = random(2) ? red : (random(2) ? green : white);
  
  // Randomly change the color of each LED
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = color;
  }
  FastLED.show();
  
  // Randomly adjust the delay to change speed
  float delayTime = random(100, 500) / 1000.0;
  delay(delayTime * 1000);
}
