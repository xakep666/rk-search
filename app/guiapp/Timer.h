/**
 * Project Untitled
 */


#ifndef _TIMER_H
#define _TIMER_H
class Timer {
public:

    void start();

    void stop();

    long long int getTime() const;

    void reset();
private:
    long long int starttime;
    long long int stoptime;
};
#endif //_TIMER_H
