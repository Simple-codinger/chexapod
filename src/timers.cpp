#include "../include/timers.h"

void timers::initialize(){
    _timer[0] = timer(&TCCR0B, PRTIM0);
    _timer[1] = timer(&TCCR1B, PRTIM1);
    _timer[2] = timer(&TCCR2B, PRTIM2);
}