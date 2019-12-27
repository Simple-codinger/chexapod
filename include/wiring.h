#ifndef WIRING_H
#define WIRING_H
class wiring{
    public:
        static uint8_t digitalPinToBitMask(uint8_t pin);
        static uint8_t* digitalPinToPort(uint8_t pin);
        static uint8_t digitalPinToTimer(uint8_t pin);
        static uint8_t* portModeRegister(uint8_t port);
};
#endif