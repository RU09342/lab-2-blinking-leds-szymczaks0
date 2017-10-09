/*AUTHOR: STEPHEN SZYMCZAK
 * PROJECT: BUTTON BLINK TOGGLE MODE:
 */
#include <msp430.h>
#include <stdio.h>
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1DIR |= BIT0;  //SET BIT0 (LED1) AS OUTPUT
    P1OUT &= ~BIT0; //SET LED1 OFF

    P1DIR &= ~BIT3; //SET P1.3 AS INPUT

    P1REN |= BIT3; //ENABLED PULL UP OR DOWN FOR P1.3
    P1OUT |= BIT3; //SPECIFIED AS A PULLUP FOR P1.3
    volatile unsigned int TOGGLE = 1;

    for(;;)
    {
        int i = 0;

        if(!(P1IN & BIT3)) {TOGGLE++; __delay_cycles(500000);} //increment toggle.
        if(TOGGLE == 6) TOGGLE = 1;
        if(TOGGLE == 5) P1OUT &= ~BIT0;
        else
        {
            i = 5000*TOGGLE;                  // SW Delay
            P1OUT ^= BIT0;
            do                         //this do-while loop handles the button blinking
            {
             i--;
             if (!(BIT3 & P1IN)) // allows for toggling to next mode while inside the do while loop.
             {
              TOGGLE++;
              __delay_cycles(500000); //don't move forward in the code for a while to give time for the button to be released
             }
            }
            while(i != 0);
        }

    }
}
