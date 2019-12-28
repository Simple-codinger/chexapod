#include <util/delay.h>
#include <stdint.h>
#include "../include/digitalPinUtil.h"

using namespace digitalPinUtil;

#define BLINK_DELAY_MS 100
 
int main()
{ 
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    
    while(1) {
        digitalWritePin(8, HIGH);
        digitalWritePin(7, LOW);
        _delay_ms(BLINK_DELAY_MS);
        digitalWritePin(8, LOW);
        digitalWritePin(7, HIGH);
        _delay_ms(BLINK_DELAY_MS);
    }
}