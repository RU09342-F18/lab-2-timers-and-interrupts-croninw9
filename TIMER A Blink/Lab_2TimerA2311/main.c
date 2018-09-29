#include <msp430.h> 


/**
 * File: main.c
 * Author: Will Cronin
 * Date Created: September 25th 2018
 * Date of Last Revision: September 27th 2018
 * Board Used: MSP430FR2311
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |= BIT0;                      // Set P1.0 to output direction
    P2DIR |= BIT0;                      // Set P2.0 to output direction

    TB0CTL = TBSSEL_2 + MC_1 + ID_3;          //Set timerA0 config to Up
    TB0CCTL0 = CCIE;                    // Set timer in compare mode
    TB0CCR0 = 0x07000;                     // Set up TAxCCR0

    TB1CTL = TBSSEL_2 + MC_1 + ID_3;          //Set timerA0 config to Up
    TB1CCTL0 = CCIE;                    // Set timer in compare mode
    TB1CCR0 = 0x04000;                     // Set up TAxCCR0

    __bis_SR_register(GIE);                       //Enables Global Interrupt
    while(1);
}

#pragma vector=TIMER0_B0_VECTOR
__interrupt void TIMER0_B0(void)
{
    P1OUT ^= BIT0;                      // Blinks LED on port 1.0
}

#pragma vector=TIMER1_B0_VECTOR
__interrupt void TIMER1_B0(void)
{
    P2OUT ^= BIT0;                      // Blinks LED on port 2.0
}

