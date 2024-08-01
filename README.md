# NES Controller Interface

A simple interface for the NES controller, allowing for the 8 buttons of the NES
controller to be read by a microcontroller.

## Hardware

The breakout board that allows for the NES Controller to be connected to a
microcontroller is available on github at
[github.com/HBoyd255/nes-controller-breakout-board](https://github.com/HBoyd255/nes-controller-breakout-board).

## Usage

Creating the interface is simple. The constructor for the
`NESControllerInterface` takes 3 pins as parameters. The first is the data pin,
the second is the latch pin, and the third is the clock pin.

```cpp
#include <NESControllerInterface.h>

// Constructor for the NESControllerInterface class.
// The first parameter is the data pin, the second is the latch pin, and the
// third is the clock pin.
NESControllerInterface nes(D8, A3, A2);
```

Then to read the buttons, a call to the `read()` function is will read the
button values as a byte.

```cpp
// Get the byte read from the controller, after it has been error checked.
uint8_t data = nes.read();
Serial.print("NES Data: ");
Serial.println(data, BIN);
```

To make reading values easier, the values can be read as a NESInput struct. This
has additional functions to check the state of the buttons.

```cpp
// Get the input from the controller, as a struct.
// This allows for the buttons to be accessed by name, rather than by bit
// manipulation.
NESInput input = nes.getNESInput();

// Print the input to the serial monitor, using implicit conversion to a
// string.
Serial.println(input);

// Print the states of the buttons to the serial monitor, using the
// statesAsString() method.
Serial.println(input.statesAsString());

// Print a comma-separated list of the buttons that are currently pressed.
Serial.print("List of pressed buttons: ");
Serial.println(input.buttonsPressedAsString());

// Print weather or not any buttons are pressed.
Serial.print("Are any buttons pressed? : ");
Serial.println((input.anyButtonPressed()) ? "Yes" : "No");

// Print out the states of the buttons individually.
Serial.print("Is the A button pressed? : ");
Serial.println((input.buttonA) ? "Yes" : "No");

Serial.print("Is the B button pressed? : ");
Serial.println((input.buttonB) ? "Yes" : "No");

Serial.print("Is the Select button pressed? : ");
Serial.println((input.buttonSelect) ? "Yes" : "No");

Serial.print("Is the Start button pressed? : ");
Serial.println((input.buttonStart) ? "Yes" : "No");

Serial.print("Is the Up button pressed? : ");
Serial.println((input.buttonUp) ? "Yes" : "No");

Serial.print("Is the Down button pressed? : ");
Serial.println((input.buttonDown) ? "Yes" : "No");

Serial.print("Is the Left button pressed? : ");
Serial.println((input.buttonLeft) ? "Yes" : "No");

Serial.print("Is the Right button pressed? : ");
Serial.println((input.buttonRight) ? "Yes" : "No");
```
