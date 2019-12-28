#include "wiring.h"

uint8_t wiring::digitalPinToBitMask(uint8_t pin){
    if(pin >= 0 && pin < 14){
        return (1 << (pin % 8));
    }
}

volatile uint8_t* wiring::digitalPinToPort(uint8_t pin){
    if(pin >= 0 && pin < 14){
        if(pin < 8){
            return &PORTD;
        }else {
            return &PORTB;
        }
    }
}

uint8_t wiring::digitalPinToTimer(uint8_t pin){ return 0; }

volatile uint8_t* wiring::portModeRegister(uint8_t port){
    if(port < 8){
        return &DDRD;
    }else {
        return &DDRB;
    }
}