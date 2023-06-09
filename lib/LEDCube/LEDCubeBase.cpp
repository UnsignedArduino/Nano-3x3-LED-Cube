#include "LEDCubeBase.h"
#include <Arduino.h>

LEDCubeBase::LEDCubeBase(ledCubeAxesLength_t width, ledCubeAxesLength_t height,
                         ledCubeAxesLength_t depth, ledCubePixelValue_t* buffer)
    : _width(width), _height(height), _depth(depth), _buffer(buffer) {}
void LEDCubeBase::begin() {}
void LEDCubeBase::end() {}

ledCubePixelValue_t* LEDCubeBase::getPointerToPixel(ledCubeAxesLength_t x,
                                                    ledCubeAxesLength_t y,
                                                    ledCubeAxesLength_t z) {
  return (this->_buffer +
          y * (this->_depth * this->_width * sizeof(ledCubePixelValue_t)) +
          z * (this->_width * sizeof(ledCubePixelValue_t)) +
          x * (sizeof(ledCubePixelValue_t)));
}

void LEDCubeBase::setPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                           ledCubeAxesLength_t z, ledCubePixelValue_t value) {
  *this->getPointerToPixel(x, y, z) = value;
}

ledCubePixelValue_t LEDCubeBase::getPixel(ledCubeAxesLength_t x,
                                          ledCubeAxesLength_t y,
                                          ledCubeAxesLength_t z) {
  return *this->getPointerToPixel(x, y, z);
}

void LEDCubeBase::fillYZPlane(ledCubeAxesLength_t x,
                              ledCubePixelValue_t value) {
  for (uint8_t z = 0; z < this->_depth; z++) {
    for (uint8_t y = 0; y < this->_height; y++) {
      this->setPixel(x, y, z, HIGH);
    }
  }
}

void LEDCubeBase::fillXZPlane(ledCubeAxesLength_t y,
                              ledCubePixelValue_t value) {
  for (uint8_t x = 0; x < this->_width; x++) {
    for (uint8_t z = 0; z < this->_depth; z++) {
      this->setPixel(x, y, z, HIGH);
    }
  }
}

void LEDCubeBase::fillXYPlane(ledCubeAxesLength_t z,
                              ledCubePixelValue_t value) {
  for (uint8_t x = 0; x < this->_width; x++) {
    for (uint8_t y = 0; y < this->_height; y++) {
      this->setPixel(x, y, z, HIGH);
    }
  }
}

void LEDCubeBase::fillCube(ledCubePixelValue_t value) {
  const uint16_t bufferSize =
      this->_width * this->_height * this->_depth * sizeof(ledCubePixelValue_t);
  memset(this->_buffer, value, bufferSize);
}

void LEDCubeBase::updateFor(uint32_t duration) {
  const uint32_t start = millis();
  while (millis() < start + duration) {
    this->update();
  }
}
