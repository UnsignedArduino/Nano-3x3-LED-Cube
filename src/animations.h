#include <Arduino.h>
#include <LEDCube.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FORWARD 4
#define BACKWARD 5

#define FRAME_TIME 250

namespace LEDCubeAnimations {
  void animationFrameBlank(LEDCubeBase& cube, uint8_t iterations);
  void animationFillCube(LEDCubeBase& cube, uint8_t iterations);
  void animationPlaneShift(LEDCubeBase& cube, uint8_t iterations,
                           uint8_t direction);
}
