/**
 * Project Untitled
 */


#include <time.h>
#include "Timer.h"
/**
 * Timer implementation
 */


void Timer::start() {
    timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);
    starttime = ts.tv_nsec;
}

void Timer::stop() {
    timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);
    stoptime = ts.tv_nsec;
}

/**
 * @return long long int
 */
long long int Timer::getTime() const {
    return stoptime-starttime;
}

void Timer::reset() {
    starttime=0;
    stoptime=0;
}
