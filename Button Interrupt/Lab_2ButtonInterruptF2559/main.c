#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1SEL = 0;              //Set port 1 as a GPIO
	P1DIR |= BIT0;          //Sets port 1.0 as an output
	P1DIR &= ~(BIT3);       //Sets port 1.3 as an input

	P1REN |= BIT3;          //Enable pull-up resistor
	P1OUT &= ~BIT0;          //Sets output for pin 1.0

	P1IE |= BIT3;           //Enable the interrupt on port 1.3
	P1IES |= BIT3;          //Set as falling edge
	P1IFG &= ~(BIT3);       //Clear interrupt flag

	_BIS_SR(GIE);           //Enables Global Interrupt

	while(1)
	{

	}
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT_1(void)
{
    P1OUT ^= 0x01;
    P1IFG &= ~(BIT3);
}
