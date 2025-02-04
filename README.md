## Notes from Author
(WIP) Updating capabilities for STM32duino.

<br/>

The following is original notes.

## ReadMe
This library can simplify user code with following functions:

    1. Function dimmerLamp - this function initializes the number of operating pin and is defined by the user
    Example: 
        a.dimmerLamp dimmer(4);    dimmer output DIM/PSM is initialized on the pin 4 for the bords WITHOUT changable ZERO-CROSS input pin (AVR, Arduino M0/Zero)
        b.dimmerLamp dimmer(4, 2);  dimmer output DIM/PSM is initialized on the pin 4 and zero-cross initialized on pin 2. Only for boards whith changable zero-cross(ESP32, ESP8266, Arduino Due)

    2. Function begin port initialization, timer and external interrupt from zero-cross.
    Example:
    dimmer.begin(NORMAL_MODE, ON/OFF); port initialization, work mode choice, ON/OFF. 
    Parameter 1: dimmer working modes consist of two choices - NORMAL_MODE and TOGGLE_MODE 
        a. NORMAL_MODE to make dimmer work in defined value from 0 to 100 (%) (integer)
            Example of this mode located in \RBDdimmer\examples\SimpleDimmer
        b. TOGGLE_MODE smooth change of dimming value up or down in a defined range. This solutions implies change of dimming values by means of hardware timer, without using the cycle code.
            Example of this mode located in \RBDdimmer\examples\SimpleToggleDimmer

    Parameter 2: ON/OFF.
        a. ON - turns timer ON, allows to use dimmer.
        b. OFF - turns timer parameters OFF, prevents the use of dimmer.

    3. Function setPower sets dimming value from 0 to 100%
        Example: dimmer.setPower(90);

    4. Function getPower to display current dimming value
        Example: Serial.print(dimmer.getPower()); Result 0~100 int
   
    5. Function setMode sets and changes the work mode (NORMAL_MODE and TOGGLE_MODE)
                dimmer.setMode(NORMAL_MODE/TOGGLE_MODE)

    6. Function getMode displays values of current work mode
        Example: Serial.print(dimmer.getPower());  Result 0 (NORMAL_MODE) or 1 (TOGGLE_MODE)
   
    7. Function setState sets dimming state ON/OFF
        Example: dimmer.setState(ON); delay(100); dimmer.setState(OFF);
   
    8. Function getState displays current state of dimmer
        Serial.print(dimmer.getState()); Result 0 (OFF) or 1 (ON)
   
    9. Function changeState changes dimmer state to the opposite one 
        Пример dimmer.setState(ON); delay(100); dimmer.changeState; delay(100);
  
    10. Function toggleSettings smooth change of dimming value up or down in a defined range
        Example located in \RBDdimmer\examples\SimpleToggleDimmer
