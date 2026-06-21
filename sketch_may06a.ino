const int micPin = A0;

const int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int soundValue = analogRead(micPin);

  // Convert microphone value to LED level (0-10)
  int level = map(soundValue, 0, 1023, 0, 10);

  // Turn LEDs on/off
  for (int i = 0; i < 10; i++) {
    if (i < level) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(20);
}
