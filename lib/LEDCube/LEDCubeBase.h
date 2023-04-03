
#pragma once

#include <Arduino.h>

typedef uint8_t ledCubeAxesLength_t;
typedef bool ledCubePixelValue_t;
typedef uint8_t ledCubePin_t;

#ifndef LED_CUBE_TIME
#define LED_TIME 300 // us
#endif

class LEDCubeBase {
  public:
    LEDCubeBase(ledCubeAxesLength_t _width, ledCubeAxesLength_t height,
                ledCubeAxesLength_t depth, ledCubePixelValue_t* buffer);
    void begin();
    void end();

    void setPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                  ledCubeAxesLength_t z, ledCubePixelValue_t value);
    ledCubePixelValue_t getPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                                 ledCubeAxesLength_t z);

    void fillCube(ledCubePixelValue_t value);

    virtual void update() = 0;

    void updateFor(uint32_t duration);

  protected:
    ledCubePixelValue_t* getPointerToPixel(ledCubeAxesLength_t x,
                                           ledCubeAxesLength_t y,
                                           ledCubeAxesLength_t z);

    ledCubeAxesLength_t _width = 0;
    ledCubeAxesLength_t _height = 0;
    ledCubeAxesLength_t _depth = 0;
    ledCubePixelValue_t* _buffer = NULL;
};
