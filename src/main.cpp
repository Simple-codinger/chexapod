#include <util/delay.h>
#include <stdint.h>
#include "../include/digitalPinUtil.h"

using namespace digitalPinUtil;

#define BLINK_DELAY_MS 1000
 
int main()
{ 
    pinMode(13, OUTPUT);
    
    while(1) {
        digitalWritePin(13, HIGH);
        _delay_ms(BLINK_DELAY_MS);
        digitalWritePin(13, LOW);
        _delay_ms(BLINK_DELAY_MS);
    }
}