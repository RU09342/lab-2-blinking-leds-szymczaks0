//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1DIR |= BIT0;  //SET BIT0 (LED1) AS OUTPUT
    P1OUT &= ~BIT0; //SET LED1 OFF

    P1DIR &= ~BIT1; //SET P1.1 AS INPUT

    P1REN |= BIT1; //ENABLED PULL UP OR DOWN FOR P1.1
    P1OUT |= BIT1; //SPECIFIED AS A PULLUP FOR P1.1

    P1IE |= BIT1;   //SET P1.1 INTERRUPT ENABLED (S2)
    P1IFG &= ~BIT1; //P1.1 IFG CLEARED

    __enable_interrupt();   //ENABLE ALL INTERRUPTS
    for(;;)
    {}

}

#pragma vector=PORT1_VECTOR
__interrupt void PORT_1(void)
{
    P1OUT ^= BIT0; //TURN ON LED
    P1IFG &= ~BIT1; //P1.5 IFG CLEARED
    P1IES ^= BIT1; //TOGGLE INTERRUPT EDGE
}
