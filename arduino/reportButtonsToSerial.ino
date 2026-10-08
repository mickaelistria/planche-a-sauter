#define BUTTON_COUNT 3

unsigned long startPress[BUTTON_COUNT + 2]; // pin 0 and 1 not used

void setup() {
  Serial.begin(9600);
  for (int pin = 2; pin < BUTTON_COUNT + 2; pin++) {
    pinMode(pin, INPUT_PULLUP);
    startPress[pin] = 0;
  }
}

#define THREESHOLD 3000 // milliseconds on a button to trigger message

void loop() {
  for (int pin = 2; pin < BUTTON_COUNT + 2; pin++) {
    if (digitalRead(pin) == HIGH) {
      startPress[pin] = 0;
    } else if (startPress[pin] == 0) {
      startPress[pin] = millis();
    } else if (millis() - startPress[pin] > THREESHOLD) {
      startPress[pin] = 0;
      Serial.print("Button"); Serial.println(pin);
    }
  }
}
