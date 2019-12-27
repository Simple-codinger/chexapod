#include "../include/robot.h"

/*
  PORTB |= (1 << PB1);  //PB1 High
  PORTB &= ~(1 << PB1); //PB1 Low
*/

Robot::Robot(){
    /* set pin 5 of PORTB for output*/
    DDRB |= _BV(DDB5);

    /* set pin 5 high to turn led on */
    PORTB = 0x20;
}

void Robot::blink(){
    if(PORTB & (1 << PB5)){
        PORTB &= ~(1 << PB5);
    }else{
        PORTB |= (1 << PB5);
    }
}