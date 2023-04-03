#include <Arduino.h>

typedef uint8_t ledCubeAxesLength_t;
typedef bool ledCubePixelValue_t;

#define LEDCubeBaseTemplate                                        \
  template <ledCubeAxesLength_t width, ledCubeAxesLength_t height, \
            ledCubeAxesLength_t depth>

LEDCubeBaseTemplate class LEDCubeBase {
  public:
    LEDCubeBase();

    void setPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                  ledCubeAxesLength_t z, ledCubePixelValue_t value);
    ledCubePixelValue_t getPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                                 ledCubeAxesLength_t z);

    void fillCube(ledCubePixelValue_t value);

    virtual void update() = 0;

  private:
    ledCubePixelValue_t buffer[height][depth][width] = {};
};
