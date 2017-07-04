/**
 Led blinker

 Fades in and out leds in pins 9, 10 and 11

 TODO:
   - when led goes off wait for a while before putting it back on
   - when led is at full power wait for some time before putting it off
*/

int brightness = 0; 
int fadeAmount = 5;

struct led {
  // The pin where led is
  int pin;
  // The brightness we last set for led
  int brightness;
  // The amount to change the brightness
  int brightnessChange;
};

typedef struct led Led;

Led leds[3];

void setup() {
  leds[0] = (Led) {9, 0, 5};
  leds[1] = (Led) {10, 150, 5};
  leds[2] = (Led) {11, 255, 5};
  // initialize led pin for output
  initializeLedPins();
}

void loop() {
  for (int i = 0; i < sizeof(leds); i++) {
    calculateNewBrightness(i);
    analogWrite(leds[i].pin, leds[i].brightness);
  }

  delay(30);
}

void initializeLedPins() {
  for (int i = 0; i < sizeof(leds); i++) {
      pinMode(leds[i].pin, OUTPUT);
  }
}

// TODO: bring the led struct as pointer to here
void calculateNewBrightness(int ledIndex) {
    if (leds[ledIndex].brightness <=0 || leds[ledIndex].brightness >= 255) {
      // TODO: get random change for brightness
      leds[ledIndex].brightnessChange = -leds[ledIndex].brightnessChange;
    }
    leds[ledIndex].brightness = leds[ledIndex].brightness + leds[ledIndex].brightnessChange;
}

void setLedBrightness(int ledPin, int brightness) {
  analogWrite(ledPin, brightness);
}
