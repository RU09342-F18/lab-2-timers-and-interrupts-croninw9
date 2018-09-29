#include <msp430.h> 


/**
 * File: main.c
 * Author: Will Cronin
 * Date Created: September 26th 2018
 * Date of Last Revision: September 26th 2018
 * Board Used: MSP430G2553
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	        // stop watchdog timer
	BCSCTL3 = LFXT1S_2;                 //Use internal crystal

	P1SEL = 0;                          //Set Pin 1 as a GPIO
	P1DIR |= 0x41;                      // Set P1.0 and P1.6 to output direction

    TA0CTL = TASSEL_2 + MC_1 + ID_3;          //Set timerA0 config to Up
	TA0CCTL0 = 0x10;                    // Set timer in compare mode
	TA0CCR0 = 0x7000;                     // Set up TAxCCR0
	TA0CCTL0 |= CCIE;                   //interrupt enable

	TA1CTL = TASSEL_2 + MC_1 + ID_3;          //Set timerA0 config to Up
    TA1CCTL0 = 0x10;                    // Set timer in compare mode
    TA1CCR0 = 0x4000;                     // Set up TAxCCR0
    TA1CCTL0 |= CCIE;                   //interrupt enable

    _BIS_SR(GIE);                       //Enables Global Interrupt
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
    P1OUT ^= 0x01;                      // Blinks LED on port 1.0
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0(void)
{
    P1OUT ^= 0x40;                      // Blinks LED on port 1.6
}
