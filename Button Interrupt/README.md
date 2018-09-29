# Button Interrupt
The Button Interrupt code allows for a LED to blink when the button is pressed. This code uses an interrupt to execute all code in the ```c __interrupt void Port_1(void) ```. This is done so the processor can go into low power mode and be more efficient than polling.

## Boards Used
* MSP430G2553
* MSP430F5529

## How the Code Works (G2553)
The code works by setting Pin 1.0 as an output and Pin 1.3 as an input. The code also enables a pull up resistor on the button to ensure accurate button presses. The code then enables an interrupt on port 1.3, sets it on the falling edge and clears the flag. Then, the global interrupt is enabled. Finally, the interrupt block of code contains the blinking LED code using the XOR function. 

### Pin Outs
Pin 1.0 - LED output 
Pin 1.3 - Button Input

## How the Code Works (F5529)
The code works by setting Pin 1.0 as an output and Pin 2.1 as an input. The code also enables a pull up resistor on the button to ensure accurate button presses. The code then enables an interrupt on port 2.1, sets it on the falling edge and clears the flag. Then, the global interrupt is enabled. Finally, the interrupt block of code contains the blinking LED code using the XOR function.

### Pin Outs
Pin 1.0 - LED Output
Pin 2.1 - Button Input
