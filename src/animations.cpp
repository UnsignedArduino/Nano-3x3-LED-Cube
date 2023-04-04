#include <Arduino.h>
#include <LEDCube.h>
#include <animations.h>

void animationFrameBlank(LEDCubeBase& cube, uint8_t iterations) {
  cube.fillCube(LOW);
  cube.updateFor(FRAME_TIME * iterations);
}

void animationFillCube(LEDCubeBase& cube, uint8_t iterations) {
  for (uint8_t i = 0; i < iterations; i++) {
    cube.fillCube(HIGH);
    cube.updateFor(FRAME_TIME);
    cube.fillCube(LOW);
    cube.updateFor(FRAME_TIME);
  }
}

void animationPlaneShift(LEDCubeBase& cube, uint8_t iterations,
                         uint8_t direction) {
  for (uint8_t i = 0; i < iterations; i++) {
    switch (direction) {
      case (UP): {
        for (uint8_t y = 0; y < cube.getHeight(); y++) {
          cube.fillCube(LOW);
          cube.fillXZPlane(y, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
      case (DOWN): {
        for (int8_t y = cube.getHeight() - 1; y >= 0; y--) {
          cube.fillCube(LOW);
          cube.fillXZPlane(y, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
      case (RIGHT): {
        for (uint8_t x = 0; x < cube.getWidth(); x++) {
          cube.fillCube(LOW);
          cube.fillYZPlane(x, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
      case (LEFT): {
        for (int8_t x = cube.getWidth() - 1; x >= 0; x--) {
          cube.fillCube(LOW);
          cube.fillYZPlane(x, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
      case (BACKWARD): {
        for (uint8_t z = 0; z < cube.getDepth(); z++) {
          cube.fillCube(LOW);
          cube.fillXYPlane(z, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
      case (FORWARD): {
        for (int8_t z = cube.getDepth() - 1; z >= 0; z--) {
          cube.fillCube(LOW);
          cube.fillXYPlane(z, HIGH);
          cube.updateFor(FRAME_TIME);
        }
        break;
      }
    }
  }
}
