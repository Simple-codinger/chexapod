#ifndef TIMERS_H
#define TIMERS_H

#define TIMERC 3

#include "timer.h"
#include <avr/io.h>
#include <stdint.h>

class timers
{
    private:
        timers( const timers& );
        timers(){};
        timers & operator = (const timers &);
        timer _timer[TIMERC];
    public:
        static timers& instance()
        {
            static timers _instance;
            return _instance;
        };
        void initialize();
        ~timers(){};
        int size = TIMERC;
        inline timer& getTimer(int i) { return _timer[i]; };
};
#endif