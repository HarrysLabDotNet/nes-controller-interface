# NES Controller Interface (Platform IO and Arduino Library)

A simple interface for the NES controller, allowing for the 8 buttons of the NES
controller to be read by a microcontroller.

## Hardware

The breakout board that allows for the NES Controller to be connected to a
microcontroller is available online at
[harryslab.net/nes-controller-breakout-board](https://harryslab.net/nes-controller-breakout-board).

# Installation (Platform IO)

To install the library, add the following to the `platformio.ini` file.

```ini
lib_deps =
    harryslabdotnet/NESControllerInterface
```

The library can also be found by searching for `NESControllerInterface` in the
PlatformIO Library Manager.

# Installation (Arduino)

- Download the repository as a ZIP file.
- Open the Arduino IDE.
- Go to `Sketch > Include Library > Add .ZIP Library...`.
- Select the ZIP file of the library.
- The library will now be installed and available under
  `Sketch > Include Library > NESControllerInterface`.

## Usage

Creating the interface is simple. The constructor for the
`NESControllerInterface` takes 3 pins as parameters. The first is the data pin,
the second is the load pin, and the third is the clock pin.

```cpp
#include <NESControllerInterface.h>

// Constructor for the NESControllerInterface class.
// The first parameter is the data pin, the second is the load pin, and the
// third is the clock pin. The GPIO pins 8, 9 and 10 have been selected for this
// example, however, any gpio pins will work.
NESControllerInterface nes(8, 9, 10);
```

Then to read the buttons, a call to the `read()` function will read the button
values as a byte.

```cpp
// Read the data from the controller as a byte.
uint8_t data = nes.read();
Serial.print("NES Data: ");
Serial.println(data, BIN);
```

To simplify reading the buttons, the values can be read as a NESInput struct.
This has additional functions to check the state of each button.

```cpp
// Get the input from the controller, as a struct.
// This allows for the buttons to be accessed by name, rather than by bit
// manipulation.
NESInput input = nes.getNESInput();

// Now each button can be read as a boolean, as follows,
if (input.buttonA) {
    // A button is pressed.
} else {
    // A button is not pressed.
}
// Additional functionality for this struct can be found in
// NESControllerInterface.h

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
