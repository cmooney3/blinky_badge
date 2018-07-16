#include <FastLED.h>

// Confiuration for the actual RGB LEDs that this controller is meant to drive.
// These settings are strip-specific and are passed to FastLED which does the
// actual control.
constexpr int kLEDPin = 4;
constexpr int kNumLEDs = 2;
CRGB leds[kNumLEDs];

constexpr int kFrameDelayMS = 5;

void setup() {
  // Initialize the main RGB LEDs
  delay(1000);
  FastLED.addLeds<WS2811, kLEDPin, GRB>(leds, kNumLEDs).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(28);
}

void loop() {
  uint8_t h = 0;
  while(1) {
    h = (h + 1) % 255;
    leds[0] = CHSV(h, 255, 128);
    leds[1] = CHSV((h + 128) % 255, 255, 128);
    FastLED.show();
    FastLED.delay(kFrameDelayMS);
  }
}
