/* AUTHOR: STEPHEN SZYMCZAK
 * MULTIPLE BUTTON BLINK FR6989
 */
#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P9DIR |= BIT7;                          // SET P9.7 TO OUTPUT DIRECTION
    P9OUT ^= BIT7;                          // START P9.7 ON TO ALTERNATE LEDS IN LOOP.
    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        P9OUT ^= BIT7;                      // Toggle LED 2
        i = 10000;                          // SW Delay
        do i--;
        while(i != 0);
        P9OUT ^= BIT7;                      // TOGGLE LED 2 twice as fast.
        i = 10000;                          // SW Delay
        do i--;
        while(i != 0);
    }
}
