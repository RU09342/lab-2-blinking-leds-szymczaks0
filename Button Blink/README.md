##### Stephen Szymczak
# LAB 2: Button Blink
 These projects all utilize PORT ISRs to recieve the input of a button and then turn an LED on and off in a blinking fashion. The specific pins vary from processor to processor, however the code structure is the same for all of them.

## Dependencies:
msp430.h must be included in the main file.

## Implementation:
This code sets a pin up as an output, the ones selected are connected to onboard LEDs.
```
PxDIR |= BITy; //sets Px.y as output 
```
After initializing the output pin, an input pin is initialized.
```
PzDIR &= ~BITw; //sets pin Pz.w as an input
PzREN |= BITw; //enables resistor for Pz.w
PzOUT |= BITw; //specifies as pull-up resistor for Pz.w
PzIE |= BITw;   //enable interrupt for Pz.w
PzIFG &= ~BITw; //Clears flag bit for Pz.w
```
Then interrupts are enabled and we enter a forever loop so that the processor is always waiting for an interrupt.
```
__enable_interrupt();   //ENABLE ALL INTERRUPTS
    for(;;)             //loop forever
    {}
```
The pin is then set high when the interrupt occurs. The input's interrupt flag bit is cleared as well as toggling the interrupt edge. Toggling the edge allows for the button to toggle rapidly while the button is held.
```
__interrupt void PORT_1(void)
{
    P1OUT ^= BIT0; //TURN ON LED
    P1IFG &= ~BIT1; //P1.5 IFG CLEARED
    P1IES ^= BIT1; //TOGGLE INTERRUPT EDGE
}
```
## Known Errors:
* There is no debouncing. This code is useful only as a learning tool.

# EXTRA work: Button Toggle Blink Rate for the G2553
Utilizing and modifying this common blink rate code:
```
for(;;) {                       //loop forever
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= 0x01;				// Toggle P1.0 using exclusive-OR

		i = 30000;					// SW Delay
		do i--;
		while(i != 0);
	}
```
line reading i = 30000; is changed to have a variable set to i:
```
i = 5000*TOGGLE;                  // SW Delay
```
This variable TOGGLE is incremented by button press code:
```
if(!(P1IN & BIT3)) {TOGGLE++; __delay_cycles(500000);}
```
This allows i to have different initial values in the forever loop, changing the rate at which the button blinks based on a button input.


