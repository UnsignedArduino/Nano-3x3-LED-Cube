#pragma once

#include "LEDCubeBase.h"
#include <Arduino.h>

class LEDCubeXZOutYIn : public LEDCubeBase {
  public:
    LEDCubeXZOutYIn(ledCubeAxesLength_t width, ledCubeAxesLength_t height,
                    ledCubeAxesLength_t depth, ledCubePixelValue_t* buffer,
                    ledCubePin_t* xzPlanePins, ledCubePin_t* yPlanePins);

    void begin();

    void update();

  private:
    ledCubePin_t* _xzPlanePins = NULL;
    ledCubePin_t* _yPlanePins = NULL;
};
