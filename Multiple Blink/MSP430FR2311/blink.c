/* AUTHOR: STEPHEN SZYMCZAK
 * MULTIPLE BUTTON BLINK FR2311
 */
#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P2DIR |= 0x01;                          // Set P2.0 to output direction
    P2OUT ^= 0x01;                          // Start LED2 ON to make the LEDS alternate being on during the loop
    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        P2OUT ^= 0x01;                      // Toggle P2.0 using exclusive-OR
        i = 10000;                          // SW Delay
        do i--;
        while(i != 0);


    }
}
