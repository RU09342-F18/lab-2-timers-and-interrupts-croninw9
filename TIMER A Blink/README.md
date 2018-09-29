# TIMER A Blink
The TIMER A Blink code makes two LEDs Blink at different frequencies. This differs from the Multiblink code from Lab 1 because of the use of interrupts as well as using timers.

## Boards Used
* MSP430G2553
* MSP430FR2311

## How the Code Works (G2553)
The code works by setting Pin 1.0 and 1.6 as an outputs. The code then creates two timers both configured to up-mode. These two timers were given different values in their timer registers and were interrupt enabled. In addition, the code enables the global interrupt. There are two different interrupt blocks of code for each timer, so each LED is set to blink in their respective timer interrupt blocks. 

### Pin Outs
Pin 1.0 - LED output 
Pin 1.6 - LED Output

## How the Code Works (FR2311)
The code works by setting Pin 1.0 and 2.0 as an outputs. The code then creates two timers both configured to up-mode. These two timers were given different values in their timer registers and were interrupt enabled. In addition, the code enables the global interrupt. There are two different interrupt blocks of code for each timer, so each LED is set to blink in their respective timer interrupt blocks. 

### Pin Outs
Pin 1.0 - LED Output
Pin 2.0 - LED Output
