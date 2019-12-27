#include "../include/robot.h"
#include "../include/digitalPinUtil.h"

using namespace pinUtil;

/*
  PORTB |= (1 << PB1);  //PB1 High
  PORTB &= ~(1 << PB1); //PB1 Low
*/

Robot::Robot(){
    /* set pin 5 of PORTB for output*/
    DDRB |= _BV(DDB5);
}

void Robot::blink(){
    writePin(PB5, PORTB, LOW);
}