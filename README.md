# Nano-3x3-LED-Cube
Code for a simple 3x3 LED Cube using the Arduino Nano.

You can find the schematic for the cube [here](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube-Schematic).

## Adding animations

To add animations, you'll need to add code in [`main.cpp`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/blob/main/src/main.cpp), [`animations.h`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/blob/main/src/animations.h), and [`animations.cpp`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/blob/main/src/animations.cpp) in the [`src/`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/tree/main/src) directory. 

### `LEDCubeBase` functions

As `LEDCubeXZOutYIn` inherits from `LEDCubeBase`, all these functions are available to you. Check out [`lib/LEDCubeBase.h`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/blob/main/lib/LEDCube/LEDCubeBase.h) for the class definition. (I'll probably forget to update this list, so you really should check out the header)

```c++
void setPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
              ledCubeAxesLength_t z, ledCubePixelValue_t value);
ledCubePixelValue_t getPixel(ledCubeAxesLength_t x, ledCubeAxesLength_t y,
                              ledCubeAxesLength_t z);

void fillYZPlane(ledCubeAxesLength_t x, ledCubePixelValue_t value);
void fillXZPlane(ledCubeAxesLength_t y, ledCubePixelValue_t value);
void fillXYPlane(ledCubeAxesLength_t z, ledCubePixelValue_t value);
void fillCube(ledCubePixelValue_t value);

virtual void update() = 0;

void updateFor(uint32_t duration);
```

## Changing wiring

The architecture of the [`LEDCube`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/tree/main/lib/LEDCube) library makes it pretty easy to change how the frame buffer is actually displayed. You'll need to create a new child class of `LEDCubeBase` and modify the `update` function to actually display what's in the frame buffer. Check out [`LEDCubeXZOutYIn`](https://github.com/UnsignedArduino/Nano-3x3-LED-Cube/tree/main/lib/LEDCube/IO/DirectIO/LEDCubeXZOutYIn) to see how I did it.
