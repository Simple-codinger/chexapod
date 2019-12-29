#include "../include/timer.h"

void timer::setClockSource(uint8_t clockSource){
    uint8_t temp = *(_clockSourceRegister) & 0xF8; //0b11111000
    *(_clockSourceRegister) = temp | clockSource;
}

void timer::power(bool power){
    if (power) { TPRR &= ~powerBit; }
    else { TPRR |= powerBit; }
}