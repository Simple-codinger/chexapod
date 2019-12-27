#ifndef pinUtil_H
#define pinUtil_H

#define HIGH 1
#define LOW 0

#define OUTPUT 1
#define INPUT 0


namespace pinUtil
{
    void writePin(uint8_t pin, volatile uint8_t& group, uint8_t output){
        switch (output)
        {
        case HIGH:
            group |= (1 << pin);
            break;
        case LOW:
            group &= ~(1 << pin);
            break;
        default:
            break;
        }
    }
}
#endif