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

void setup() {
  // initialize led pin for output
  initializeLedPins();
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(ledPins); i++) {
    analogWrite(ledPins[i], ledBrightness[i]);
    if (ledBrightness[i] <=0 || ledBrightness[i] >= 255) {
      ledBrightnessFading[i] = !ledBrightnessFading[i];
    }
    if (ledBrightnessFading[i]) {
      ledBrightness[i] = ledBrightness[i] - fadeAmount;
    } else {
      ledBrightness[i] = ledBrightness[i] + fadeAmount;
    }
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

void log(String message) {
  Serial.print("log: ");
  Serial.print(message);
  Serial.print("\n");
}
