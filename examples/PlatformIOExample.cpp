/**
 * @file PlatformIOExample.cpp
 * @brief Example code for the NESControllerInterface library.
 *
 * @author Harry Boyd - https://github.com/HBoyd255
 * @date 28/12/2024
 * @copyright Copyright (c) 2024
 */
#include <NESControllerInterface.h>

// The GPIO pins 8, 9 and 10 have been selected for this example,
// however, any gpio pins will work.
#define DATA_PIN D8
#define LOAD_PIN D9
#define CLOCK_PIN D10

// Constructor for the NESControllerInterface class.
// The first parameter is the data pin, the second is the load pin, and the
// third is the clock pin.
NESControllerInterface nes(DATA_PIN, LOAD_PIN, CLOCK_PIN);

void setup() {
    // Initialize the serial monitor.
    Serial.begin(9600);
}

void loop() {
    // Read the data from the controller as a byte directly from the controller,
    // without error checking. This is just supposed to be used for debugging
    // purposes.
    uint8_t rawData = nes.readRaw();
    Serial.print("NES Data Raw: ");
    Serial.println(rawData, BIN);

    // Read the data from the controller as a byte.
    uint8_t data = nes.read();
    Serial.print("NES Data: ");
    Serial.println(data, BIN);

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

    Serial.println("--------------------------------------------------");

    // Delay to make the serial monitor easier to read.
    delay(1000);
}