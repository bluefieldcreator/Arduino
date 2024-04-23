const int wait_time = 500;
const int pines[] = {13, 12, 11, 10, 9};
const int numPins = sizeof(pines) / sizeof(pines[0]);

void setup() {
  for (int n = 0; n < numPins; n++) {
    pinMode(pines[n], OUTPUT);
  }
}

void setAll(int state) {
  for (int n = 0; n < numPins; n++) {
    digitalWrite(pines[n], state);
  }
  delay(wait_time);
}

void reverseLoop() {
  for (int i = numPins - 1; i >= 0; i--) {
    digitalWrite(pines[i], 1);
    delay(wait_time);
    digitalWrite(pines[i - 1], 0);
    delay(wait_time);
  }
}

void forwardLoop() {
  for (int n = 0; n < numPins; n++) {
    digitalWrite(pines[n], 1);
    delay(wait_time);
    digitalWrite(pines[n + 1], 0);
    delay(wait_time);
  }
}

void loop() {
  forwardLoop();
  setAll(0);
  reverseLoop();
  setAll(0);
  setAll(1);
  setAll(0);
  setAll(1);
  setAll(0);
}
