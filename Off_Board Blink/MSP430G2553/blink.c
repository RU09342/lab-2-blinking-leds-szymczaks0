//  AUTHOR: Stephen Szymczak
//  PROJECT:MULTIPLE BLINK FOR G2553
//***************************************************************************************

#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P1DIR |= BIT6;                  // configure P1.6 as output
	P1OUT ^= 0x01;              // toggle P1.0
	volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
	    for(i=10000; i>0; i--);     // delay
		P1OUT ^= 0x01;				// toggle P1.0
		P1OUT ^= BIT6;
		for(i=10000; i>0; i--);     // delay
		P1OUT ^= BIT6;              //toggle P1.6

	}
}

