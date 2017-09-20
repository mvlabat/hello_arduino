#include <Arduino.h>

int switchState = 0;

const int GREEN = 7;
const int URED = 4;
const int DRED = 2;
const int INPUT_PIN = 12;

void setup() {
    pinMode(DRED, OUTPUT);
    pinMode(URED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(INPUT_PIN, INPUT);
}

void play(int color, int duration) {
    digitalWrite(color, HIGH);
    delay(duration - 100);
    digitalWrite(color, LOW);
    delay(100);
}

void loop() {
    switchState = digitalRead(INPUT_PIN);
    switch (switchState) {
        case HIGH:
            digitalWrite(GREEN, LOW);
            play(URED, 200);
            play(URED, 200);
            play(URED, 200);
            play(DRED, 200 * 9);

        default:
            digitalWrite(GREEN, HIGH);
            digitalWrite(URED, LOW);
            digitalWrite(DRED, LOW);
    }
}
