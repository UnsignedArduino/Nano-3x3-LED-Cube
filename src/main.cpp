#include <Arduino.h>
#include <LEDCube.h>

const ledCubeAxesLength_t WIDTH = 3;
const ledCubeAxesLength_t HEIGHT = 3;
const ledCubeAxesLength_t DEPTH = 3;

const ledCubePin_t XZ_PLANE_PINS[WIDTH * DEPTH] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const ledCubePin_t Y_PLANE_PINS[HEIGHT] = {A0, A1, A2};

ledCubePixelValue_t buffer[HEIGHT][DEPTH][WIDTH] = {};

LEDCubeXZOutYIn cube(WIDTH, HEIGHT, DEPTH, (ledCubePixelValue_t*)buffer,
                     (ledCubePin_t*)XZ_PLANE_PINS, (ledCubePin_t*)Y_PLANE_PINS);

void setup() {
  cube.begin();
}

void loop() {
  for (uint8_t y = 0; y < HEIGHT; y++) {
    for (uint8_t x = 0; x < WIDTH; x++) {
      for (uint8_t z = 0; z < DEPTH; z++) {
        cube.setPixel(x, y, z, HIGH);
        cube.updateFor(100);
        cube.fillCube(LOW);
      }
    }
  }
}
