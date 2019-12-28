#ifndef WIRING_H
#define WIRING_H

 #include <stdint.h>
 #include <avr/io.h>

class wiring{
    public:
        static uint8_t digitalPinToBitMask(uint8_t pin);
        static volatile uint8_t* digitalPinToPort(uint8_t pin);
        static uint8_t digitalPinToTimer(uint8_t pin);
        static volatile uint8_t* portModeRegister(uint8_t port);
};
#endif