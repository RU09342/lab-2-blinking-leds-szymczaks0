#### Stephen Szymczak
# LAB 2: simple Blink
  We begin exploring the MSP430 boards: MSP430G2553, MSP430FR6989, MSP430FR2311, MSP430F5529L, and MSP430FR5994. Each of these boards are programmed in C, and thus logic structure of code will be the same. However, not all of the boards have the same syntax for modifying their registers, and furthermore, their pinout labels are different. This project is a tool to become familiar with how the boards are similar but different.

## Dependencies
msp430.h is required in the main file.

## Usage
Getting started with MSP430 programming, we find there are a lot of registers that are defined in msp430.h. These differ from board to board. For example, one board may have an LED connected to P1.2, while another will have an LED connected to P4.7.

To enable an LED connected pin, we need to utilize some of the syntax from the msp430.h file:
```
P1DIR |= 0x01;					// Set P1.0 to output direction
```
This sets bit 0 in the P1DIR register to 1. P1DIR dictates if a pin on PORT1 is an input or an output. Setting a bit high makes the corresponding pin an output, and an input if the bit is set low. '|=' is used to logically OR the P1DIR register with 0x01, setting the last pin high and thus an output.

We then utilize a forever loop that counts down an integer 'i' and toggle a pin that is connected to an LED. By using '^=' (exclusive-or) we toggle the pin each time the loop is iterated, producing a blink.
```
for(;;) {                       //loop forever
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= 0x01;				// Toggle P1.0 using exclusive-OR

		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
	}
```
The code in this readme is used in the G2553 simple blink project.
