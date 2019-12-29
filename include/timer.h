#ifndef TIMER_H
#define TIMER_H

#define TPRR PRR

#include <stdint.h>
#include <avr/io.h>


class timer{
    private:
        volatile uint8_t* _clockSourceRegister;

    public:
        volatile uint8_t powerBit;

        timer(){};
        timer(volatile uint8_t* clockSourceRegister, volatile uint8_t pb) : _clockSourceRegister(clockSourceRegister), powerBit(pb) {};
        void setClockSource(uint8_t clockSource);
        void power(bool power);
};
#endif