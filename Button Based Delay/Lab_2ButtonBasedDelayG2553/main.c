#include <msp430.h> 


/**
 * File: main.c
 * Author: Will Cronin
 * Date Created: September 26th 2018
 * Date of Last Revision: September 27th 2018
 * Board Used: MSP430G2553
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	BCSCTL3 = LFXT1S_2;                 //Use internal crystal
	
	//P1SEL = 0;       //Sets Pin 1.0 as a GPIO
	P1DIR |= BIT0;       //Sets Pin 1.0 as an output
	P1DIR &= ~BIT3;      //Sets Pin 1.3 as an input

	P1REN |= BIT3;          //Enable pull-up resistor
    P1OUT &= ~BIT0;         //Sets output for pin 1.0

    P1IE |= BIT3;           //Enable the interrupt on port 1.3
    P1IES |= BIT3;          //Set as falling edge
    P1IFG &= ~(BIT3);       //Clear interrupt flag

    TA0CTL = TASSEL_1 + MC_1 + ID_1;    //Set timerA0 config to Up
    CCTL0 = CCIE;                       //Enable capture compare interrupt
    TA0CCR0 = 300;                     // Set up TAxCCR0

    _BIS_SR(LPM0_bits + GIE);                       //Enables Global Interrupt

}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
    P1OUT ^= 0x01;                      // Blinks LED on port 1.0
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT_1(void)
{
    if(P1IES & BIT3)                //checks for falling edge
    {
        P1IES &= ~BIT3;                 //change to rising edge
        TACTL = TACLR;                      //clear timer
        TA0CTL = TASSEL_1 + MC_2 + ID_1;    //sets it to continuous
    }
    else
    {
        TA0CTL = MC_0;                  //stop timer
        CCR0 = TA0R;                     // Set CCR0 to value in timer
        TACTL |= TACLR;                 //Sets timer to zero
        TA0CTL = TASSEL_1 + MC_1 + ID_1;    //sets it to continuous
        P1IES |= BIT3;                  //change to falling edge


    }
    P1IFG &= ~(BIT3);       //Clear interrupt flag
}




