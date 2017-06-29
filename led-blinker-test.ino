/**
 Led blinker

 Fades in and out leds in pins 9, 10 and 11

 TODO:
   - when led goes off wait for a while before putting it back on
   - when led is at full power wait for some time before putting it off
*/

const int ledPins[] = { 9, 10, 11 };

int ledBrightness[] = {0, 150, 255};
bool ledBrightnessFading[] = {true, true, false};

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

const Led leds[3];

void setup() {
  leds[0] = (Led) {9, 0, 5};
  leds[1] = (Led) {10, 150, 5};
  leds[2] = (Led) {11, 255, 5};
  // initialize led pin for output
  initializeLedPins();
}

void loop() {
  for (int i = 0; i < sizeof(leds); i++) {
    analogWrite(leds[i].pin, leds[i].brightness);
    if (leds[i].brightness <=0 || leds[i].brightness >= 255) {
      // TODO: get random change for brightness
      // TODO: function for the struct to handle calculating new brightness
      leds[i].brightnessChange = -leds[i].brightnessChange;
    }
    leds[i].brightness = leds[i].brightness + leds[i].brightnessChange;
  }

  delay(30);
}

void initializeLedPins() {
  for (int i = 0; i < sizeof(ledPins); i++) {
      pinMode(ledPins[i], OUTPUT);
  }
}

void setLedBrightness(int ledPin, int brightness) {
  analogWrite(ledPin, brightness);
}
