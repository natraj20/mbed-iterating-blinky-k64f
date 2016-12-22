#include "mbed.h"

DigitalOut redLed(LED_RED);
DigitalOut greenLed(LED_GREEN);
DigitalOut blueLed(LED_BLUE);

#define SPEED 1.0
#define LED_COUNT 3
#define LED_OFF 1
#define LED_ON 0

void turnOffLeds(DigitalOut *leds[], int length) {
  for (int i = 0; i < length; i++) {
    *leds[i] = LED_OFF;
  }
}

void iterateLeds(DigitalOut *leds[], int length) {
  for (int i = 0; i < length; i++) {
    DigitalOut currentLed = *leds[i];
    currentLed = LED_ON;
    wait(SPEED);
    currentLed = LED_OFF;
    wait(SPEED);
  }
}

int main() {
  DigitalOut *leds[LED_COUNT] = {
    &redLed, &greenLed, &blueLed
  };

  turnOffLeds(leds, LED_COUNT);

  while(1) {
    iterateLeds(leds, LED_COUNT);
  }
}
