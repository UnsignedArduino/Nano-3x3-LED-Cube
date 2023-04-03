#include <Arduino.h>

const uint8_t WIDTH = 3;
const uint8_t HEIGHT = 3;
const uint8_t DEPTH = 3;

const uint8_t XZ_PLANE_PINS[WIDTH * DEPTH] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const uint8_t Y_PLANE_PINS[HEIGHT] = {A0, A1, A2};

const uint16_t LED_TIME = 300; // us

bool buffer[HEIGHT][DEPTH][WIDTH] = {};

void showBuffer(uint32_t duration) {
  uint32_t start = millis();
  while (millis() < start + duration) {
    for (uint8_t yPlane = 0; yPlane < HEIGHT; yPlane++) {
      digitalWrite(Y_PLANE_PINS[yPlane], LOW);
      for (uint8_t zRow = 0; zRow < DEPTH; zRow++) {
        for (uint8_t xRow = 0; xRow < WIDTH; xRow++) {
          digitalWrite(XZ_PLANE_PINS[zRow * 3 + xRow], buffer[yPlane][zRow][xRow]);
        }
      }
      delayMicroseconds(LED_TIME);
      for (uint8_t zRow = 0; zRow < DEPTH; zRow++) {
        for (uint8_t xRow = 0; xRow < WIDTH; xRow++) {
          digitalWrite(XZ_PLANE_PINS[zRow * 3 + xRow], LOW);
        }
      }
      digitalWrite(Y_PLANE_PINS[yPlane], HIGH);
    }
  }
}

void setPixel(uint8_t x, uint8_t y, uint8_t z, bool value) {
  buffer[y][z][x] = value;
}

bool getPixel(uint8_t x, uint8_t y, uint8_t z) {
  return buffer[y][z][x];
}

void setAll(bool value) {
  const uint16_t bufferSize = WIDTH * HEIGHT * DEPTH * sizeof(bool);
  memset(buffer, value, bufferSize);
}

void setup() {
  Serial.begin(9600);
  for (uint8_t i = 0; i < WIDTH * DEPTH; i ++) {
    pinMode(XZ_PLANE_PINS[i], OUTPUT);
    digitalWrite(XZ_PLANE_PINS[i], LOW);
  }
  for (uint8_t i = 0; i < HEIGHT; i ++) {
    pinMode(Y_PLANE_PINS[i], OUTPUT);
    digitalWrite(Y_PLANE_PINS[i], HIGH);
  }
}

void loop() {
  for (uint8_t y = 0; y < HEIGHT; y ++) {
    for (uint8_t x = 0; x < WIDTH; x ++) {
      for (uint8_t z = 0; z < DEPTH; z ++) {
        setPixel(x, y, z, HIGH);
        showBuffer(1000);
        setAll(LOW);
      }
    }
  }
}
