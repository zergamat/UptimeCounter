// Simple, not accurate uptime counter based on millis(). Counts beyound rollovers.

#ifndef UPTIMECOUNTER_H
#define UPTIMECOUNTER_H

#include <Arduino.h>

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
    //                                          4294967295 for arduino uno
    //                                          4294967295 for ESP8266
    //                                          4294967295 for ESP32
    static const unsigned long DS_IN_HOUR = 36000; //decisecounds
    static const unsigned long DS_IN_MINUTE = 600; //decisecounds
    static const unsigned long DS_IN_SECOUND = 10; //decisecounds

public:
    UptimeCounter(int tickerCallPeriod = TICKER_DEFAULT_PERIOD);
    char *uptime(); // - returns cstring in format: DDd HH:MM:SS (1d 12:05:56)
    unsigned long days();
    unsigned long hours();
    unsigned long minutes();
    unsigned long secounds();
    void update(); // - have to be in main loop
    // ~UptimeCounter();
};


#endif