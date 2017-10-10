#### Stephen Szymczak
# LAB 2: Multiple Blink
After completing simple blink, a logical next step is seeing how that code can be changed to effect 2 LEDs.


## Dependencies
msp430.h is required in the main file.

## Implementation
This project depends heavily on the code used for simple blink. The main difference is setting up a second output pin, and making that second pin blink at a different rate.

Simple blink utilized this common forever loop with toggling output:
```
for(;;) {                       //loop forever
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= 0x01;				// Toggle P1.0 using exclusive-OR

		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
	}
```
The first change to incorporate a second LED is activating another LED's pin as an output:
```
P1DIR |= BIT6;
```
The second step is including the XOR toggling inside the forever loop. After adding a secondary i count down loop we get code that has one LED blink twice as fast as the other:
```
	while(1)
	{
	    for(i=10000; i>0; i--);     // delay
		P1OUT ^= 0x01;				// toggle P1.0
		P1OUT ^= BIT6;              // toggle P1.6
		for(i=10000; i>0; i--);     // second delay for P1.6
		P1OUT ^= BIT6;              //toggle P1.6

	}
```


