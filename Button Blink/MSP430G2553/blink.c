/*AUTHOR: STEPHEN SZYMCZAK
 * PROJECT: BUTTON BLINK FOR G2553
 */
#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1DIR |= BIT0;  //SET BIT0 (LED1) AS OUTPUT
    P1OUT &= ~BIT0; //SET LED1 OFF

    P1DIR &= ~BIT3; //SET P1.3 AS INPUT

    P1REN |= BIT3; //ENABLED PULL UP OR DOWN FOR P1.3
    P1OUT |= BIT3; //SPECIFIED AS A PULLUP FOR P1.3

    P1IE |= BIT3;   //SET P1.3 INTERRUPT ENABLED (S2)
    P1IFG &= ~BIT3; //P1.3 IFG CLEARED

    __enable_interrupt();   //ENABLE ALL INTERRUPTS
    for(;;)
    {}

}

#pragma vector=PORT1_VECTOR
__interrupt void PORT_1(void)
{
    P1OUT ^= BIT0; //TURN ON LED
    P1IFG &= ~BIT3; //P1.5 IFG CLEARED
    P1IES ^= BIT3; //TOGGLE INTERRUPT EDGE
}
