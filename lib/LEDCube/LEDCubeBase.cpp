#include <Arduino.h>
#include <LEDCubeBase.h>

#define LEDCubeBaseFunctionTemplate LEDCubeBase<width, height, depth>

LEDCubeBaseTemplate LEDCubeBaseFunctionTemplate::LEDCubeBase() {}

LEDCubeBaseTemplate void LEDCubeBaseFunctionTemplate::setPixel(
    ledCubeAxesLength_t x, ledCubeAxesLength_t y, ledCubeAxesLength_t z,
    ledCubePixelValue_t value) {}
