#include <Arduino.h>
#include <LEDCube.h>
#include <animations.h>

const ledCubeAxesLength_t WIDTH = 3;
const ledCubeAxesLength_t HEIGHT = 3;
const ledCubeAxesLength_t DEPTH = 3;

const ledCubePin_t XZ_PLANE_PINS[WIDTH * DEPTH] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const ledCubePin_t Y_PLANE_PINS[HEIGHT] = {A0, A1, A2};

const uint8_t ANIMATION_ITERATIONS = 2;

ledCubePixelValue_t buffer[HEIGHT][DEPTH][WIDTH] = {};

LEDCubeXZOutYIn cube(WIDTH, HEIGHT, DEPTH, (ledCubePixelValue_t*)buffer,
                     (ledCubePin_t*)XZ_PLANE_PINS, (ledCubePin_t*)Y_PLANE_PINS);

void setup() {
  // Serial.begin(9600);
  cube.begin();
}

void loop() {
  // animationFillCube(cube, ANIMATION_ITERATIONS);
  // animationFrameBlank(cube, 1);
  animationPlaneShift(cube, ANIMATION_ITERATIONS, UP);
  animationFrameBlank(cube, 1);
  animationPlaneShift(cube, ANIMATION_ITERATIONS, DOWN);
  animationFrameBlank(cube, 1);
}
