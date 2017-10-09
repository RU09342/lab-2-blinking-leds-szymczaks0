/* AUTHOR: STEPHEN SZYMCZAK
 * MULTIPLE BUTTON BLINK FR5994
 */
#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1.0 to output direction
    P1OUT ^= BIT1;
    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization
        P1OUT ^= 0x03;                      // Toggle P1.0 & P1.2 using exclusive-OR

        i = 10000;                          // SW Delay
        do i--;
        while(i != 0);
        P1OUT ^= 0x02;                      // toggle p1.2 again to achieve different rate
        i = 15000;
        do i--;
        while(i != 0);
    }
}
