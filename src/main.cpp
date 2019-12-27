#include <util/delay.h>
#include "../include/robot.h"

#define BLINK_DELAY_MS 1000
 
int main()
{ 
    Robot robot;
    while(1) {
        robot.blink();
        _delay_ms(BLINK_DELAY_MS);
    }
}