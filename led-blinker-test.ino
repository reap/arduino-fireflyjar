int led = 13;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  // initialize led pin for output
  pinMode(led, OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, brightness);

  brightness = brightness + fadeAmount;

  if (brightness <=0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    log("Turning direction");
  }

  delay(30);
}

void log(String message) {
  Serial.print("log: ");
  Serial.print(message);
  Serial.print("\n");
}
