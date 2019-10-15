/*
    Author: Abdullah Nibah Hussain, S1800980
    
    A simple thermometer that reads the current temperature and is able to convert between celsius, fahrenheit
    and kelvin. Shaking the micro:bit might reveal a special easter egg.
    
 */
#include "MicroBit.h"

//creating all the objects necessary for the program to run
//MicroBit object named uBit
MicroBit uBit;
//MicroBitStorage object named storage 
MicroBitStorage storage; 
//MicroBitThermometer object named thermometer that stores information in storage
MicroBitThermometer thermometer(storage); 
//MicroBitButton object named buttonA used to detect inputs to button A
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A); 
//MicroBitButton object named buttonB used to detect inputs to button B
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B); 
//MicroBitI2C object named i2c used by the accelerometer
MicroBitI2C i2c = MicroBitI2C(I2C_SDA0, I2C_SCL0); 
//MicroBitAccelerometer object named accelerometer
MicroBitAccelerometer accelerometer = MicroBitAccelerometer(i2c); 

//start of the main program
int main() {
    //initializing uBit
    uBit.init();
    //initializing temperature variable
    int temperature = 0; 
    //start of loop
    while (1) { 
    //initializing variables used by accelerometer to detect shakes
    int x = accelerometer.getX();
    int y = accelerometer.getY();
    //shake detection and easter egg
    if  (x > 900 and y > 900) {
        uBit.display.scroll("Hello There!");
        }
    //temperature in kelvin
    if  (buttonA.isPressed() and buttonB.isPressed()) {       
        temperature = thermometer.getTemperature();
        x = temperature + 273.15;
        uBit.display.scroll(x);
        }        
    //temperature in fahrenheit
    else if  (buttonA.isPressed()) {
        temperature = thermometer.getTemperature();
        x = (temperature * 9/5) + 32;
        uBit.display.scroll(x);
        }
    //temperature in celsius
    else if  (buttonB.isPressed()) {
        temperature = thermometer.getTemperature();  
        uBit.display.scroll(temperature);
        }    
    }
}



