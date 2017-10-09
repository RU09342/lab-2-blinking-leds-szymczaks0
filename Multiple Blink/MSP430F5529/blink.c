/* AUTHOR: STEPHEN SZYMCZAK
 * MULTIPLE BUTTON BLINK F5529
 */
#include <msp430.h>				

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P4DIR |= BIT7;                  // configure P4.7 as output
	P4OUT ^=BIT7;                   // Start P4.7 on so that the LEDs alternate being on in the loop
	volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
		P1OUT ^= 0x01;				// toggle P1.0
		P4OUT ^=BIT7;
		for(i=10000; i>0; i--);     // delay
	}
}
