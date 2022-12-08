// Simple, not accurate uptime counter based on millis(). Counts beyound rollovers.

#ifndef UPTIMECOUNTER_H
#define UPTIMECOUNTER_H

#include <Arduino.h>
#include <Ticker.h>

class Ticker;

class UptimeCounter
{
private:
    Ticker *ticker;
    bool checkIfOneDigitNumber(unsigned long);
    void precedingZero(unsigned long, char*);
    static void tick();
    static const int TICKER_DEFAULT_PERIOD = 1; //seconds
    static const unsigned long DS_IN_ROLLOVER = 42949673; //decisecounds in rollover
    static const unsigned long DS_IN_DAY = 864000; //decisecounds in day
    static const unsigned long DS_IN_HOUR = 36000; //decisecounds
    static const unsigned long DS_IN_MINUTE = 600; //decisecounds
    static const unsigned long DS_IN_SECOUND = 10; //decisecounds

public:
    UptimeCounter(int tickerCallPeriod = TICKER_DEFAULT_PERIOD);
    // uptime() - returns cstring in format: DDd HH:MM:SS (1d 12:05:56)
    char* uptime();
    unsigned long days();
    unsigned long hours();
    unsigned long minutes();
    unsigned long secounds();
    // ~UptimeCounter();
};


#endif