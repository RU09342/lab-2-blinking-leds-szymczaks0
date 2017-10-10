#### Stephen Szymczak
# LAB 2: Off Board Blink
Utilizing already written code, the G2553 processor is removed from its development board and placed on a breadboard where required circuitry is put in place to run multiple blink code.

## Required Materials
  * Breadboard
  * Jumper Cables
  * 3.3V and GND connections from the launchpad board
  * 4.6k resistors
  * LEDs (Red LEDs are recommended)
  * G2553 Processor
## Setup
### 0. Test that multiple blink code works properly while the G2553 is still connected to the launchpad.
### 1. Remove power from the launchpad (micro USB cable)
### 2. Connect, with wires, 3.3V pin on the launchpad to the + rail on the breadboard & the GND pin on the launchpad to the - rail on the breadboard.

### 3.  The bare minimum to flash two LEDs with the G2553 on a breadboard are 5 pin connects: 
   * VCC
   * GND
   * !RST
   * P1.0 (LED 1)
   * P1.6 (LED 2)
### VCC
   VCC will be connected, with a wire, to the + rail on the breadboard.
### GND
   GND will be connected, with a wire, to the - rail on the breadboard.
### !RST
   This is the negative logic reset, for our purposes this will simply be connected, with a 4.6k resistor, to the + rail on the breadboard.
### P1.0 (LED 1) & P1.6 (LED 2)
   P1.0 will be connected, with a 4.6k resistor, to the anode of an LED, the cathode of the LED will be connected, with a wire, to the - rail on the breadboard. Repeat this step with P1.6.
### 4.  Plug the launchpad back into power (micro USB)

The two LEDs should now be blinking at the same rate as they were when they were on the launchpad. If they are blinking very fast. !RST may not be connected correctly. If nothing happens, carefully review the guide.

[Here](https://imgur.com/a/1hWPI) is a link to a gif demo of the offboard blink working.

