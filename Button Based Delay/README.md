# Button Based Delay
The Button Based Delay code is defaulted to have an LED blink at 10Hz. However when the button is held and released, the amount of time the button is held is the new period for the blinking LED

## Boards Used
* MSP430G2553
* MSP43XXXXXX

## How the Code Works (G2553)
The code works by setting Pin 1.0 as an output and Pin 1.3 as an input. The code also enables a pull up resistor on the button to ensure accurate button presses. The code then enables an interrupt on port 1.3, sets it on the falling edge and clears the flag. Then, the global interrupt is enabled. The code has two interrupt blocks: one for the timer that blinks the LED and another for the button. The interrupt block of code for the button works where if the button is pressed, the timer goes to zero and starts counting in continuous mode. When the button is released, the timer value is stored in the timer register, the timer is set back to zero, and the timer is set back to counting in up mode. 

### Pin Outs
Pin 1.0 - LED output 
Pin 1.3 - Button Input

## How the Code Works (XXXXX)


### Pin Outs
