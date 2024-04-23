#define wait_time 500

int pines[] = { 13, 12, 11, 10, 9 };

void setup() {
  int length = sizeof(pines) / sizeof(pines[0]);
  for (int n = 0; n < length; n++) {
    pinMode(pines[n], OUTPUT);
  }
}

void setAll(int state) {
  int length = sizeof(pines) / sizeof(pines[0]);
  for (int n = 0; n < length; n++) {
    digitalWrite(pines[n], state);
  }
  delay(wait_time);
}

void reverseLoop() {
  int length = sizeof(pines) / sizeof(pines[0]);

  for (int i = length - 1; i >= 0; i--) {
    digitalWrite(pines[i], 1);
    delay(wait_time);
    digitalWrite(pines[i - 1], 0);
    delay(wait_time);
  }
}

void forwardLoop() {
  int length = sizeof(pines) / sizeof(pines[0]);

  for (int n = 0; n < length; n++) {
    digitalWrite(pines[n], 1);
    delay(200);
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
