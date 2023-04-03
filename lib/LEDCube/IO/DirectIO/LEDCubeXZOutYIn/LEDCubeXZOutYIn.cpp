#include "LEDCubeXZOutYIn.h"
#include <Arduino.h>

LEDCubeXZOutYIn::LEDCubeXZOutYIn(ledCubeAxesLength_t width,
                                 ledCubeAxesLength_t height,
                                 ledCubeAxesLength_t depth,
                                 ledCubePixelValue_t* buffer,
                                 ledCubePin_t* xzPlanePins,
                                 ledCubePin_t* yPlanePins)
    : LEDCubeBase(width, height, depth, buffer), _xzPlanePins(xzPlanePins),
      _yPlanePins(yPlanePins) {}

void LEDCubeXZOutYIn::begin() {
  for (uint8_t i = 0; i < this->_width * this->_depth; i++) {
    pinMode(this->_xzPlanePins[i], OUTPUT);
    digitalWrite(this->_xzPlanePins[i], LOW);
  }
  for (uint8_t i = 0; i < this->_height; i++) {
    pinMode(this->_yPlanePins[i], OUTPUT);
    digitalWrite(this->_yPlanePins[i], HIGH);
  }
}

void LEDCubeXZOutYIn::update() {
  for (uint8_t yPlane = 0; yPlane < this->_height; yPlane++) {
    digitalWrite(this->_yPlanePins[yPlane], LOW);
    for (uint8_t zRow = 0; zRow < this->_depth; zRow++) {
      for (uint8_t xRow = 0; xRow < this->_width; xRow++) {
        digitalWrite(this->_xzPlanePins[zRow * 3 + xRow],
                     *this->getPointerToPixel(xRow, yPlane, zRow));
      }
    }
    delayMicroseconds(LED_TIME);
    for (uint8_t zRow = 0; zRow < this->_depth; zRow++) {
      for (uint8_t xRow = 0; xRow < this->_width; xRow++) {
        digitalWrite(this->_xzPlanePins[zRow * 3 + xRow], LOW);
      }
    }
    digitalWrite(this->_yPlanePins[yPlane], HIGH);
  }
}
