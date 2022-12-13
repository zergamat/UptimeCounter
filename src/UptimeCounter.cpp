#include "UptimeCounter.h"

static unsigned long Rollovers = 0;
static unsigned long MillisGuard = 0;
static unsigned long PmUpdate = 0;
static char GlobalBuffer[20] = "";

UptimeCounter::UptimeCounter(int tickerCallPeriod)
{
    MillisGuard = millis();
}

void UptimeCounter::update()
{
    if (millis() - PmUpdate > TICKER_DEFAULT_PERIOD * 1000)
    {
    
    if (millis() > MillisGuard)
    {
        MillisGuard = millis();
    }
    else
    {
        Rollovers++;
        MillisGuard = millis();else
    }
    }
    PmUpdate = millis();
}

void UptimeCounter::tick()
{
    if (millis() > MillisGuard) {
        MillisGuard = millis();
    }
    else
    {
        Rollovers++;
        MillisGuard = millis();
    }
}

unsigned long UptimeCounter::days()
{
    unsigned long decisecoundsPassed = Rollovers * DS_IN_ROLLOVER + millis() / 100;
    int daysPassed = decisecoundsPassed / DS_IN_DAY;
    return daysPassed;
}

unsigned long UptimeCounter::hours()
{
    unsigned long decisecoundsPassed = Rollovers * DS_IN_ROLLOVER + millis() / 100;
    unsigned long hoursPassed = decisecoundsPassed / DS_IN_HOUR;
    return hoursPassed;
}

unsigned long UptimeCounter::minutes()
{
    unsigned long decisecoundsPassed = Rollovers * DS_IN_ROLLOVER + millis() / 100;
    unsigned long minutesPassed = decisecoundsPassed / DS_IN_MINUTE;
    return minutesPassed;
}

unsigned long UptimeCounter::secounds()
{
    unsigned long decisecoundsPassed = Rollovers * DS_IN_ROLLOVER + millis() / 100;
    unsigned long secoundsPassed = decisecoundsPassed / DS_IN_SECOUND;
    return secoundsPassed;
}

char *UptimeCounter::uptime()
{
    unsigned long decisecoundsPassed = Rollovers * DS_IN_ROLLOVER + millis()/100;
    unsigned long daysToPrint = decisecoundsPassed / DS_IN_DAY;
    unsigned long hoursToPrint = (decisecoundsPassed % DS_IN_DAY) / DS_IN_HOUR;
    unsigned long minutesToPrint = (decisecoundsPassed % DS_IN_HOUR) / DS_IN_MINUTE;
    unsigned long secoundsToPrint = (decisecoundsPassed % DS_IN_MINUTE) / DS_IN_SECOUND;

    // building cstring in format: DDd HH:MM:SS
    char buffer[10] = "";
    // clearing GlobalBuffer
    GlobalBuffer[0] = '\0';
    // change long to char array
    ltoa(daysToPrint, buffer, 10);
    strcat(GlobalBuffer, buffer);
    strcat(GlobalBuffer, "d ");
    precedingZero(hoursToPrint, buffer);
    strcat(GlobalBuffer, buffer);
    strcat(GlobalBuffer, ":");
    precedingZero(minutesToPrint, buffer);
    strcat(GlobalBuffer, buffer);
    strcat(GlobalBuffer, ":");
    precedingZero(secoundsToPrint, buffer);
    strcat(GlobalBuffer, buffer);
    return GlobalBuffer;
}

bool UptimeCounter::checkIfOneDigitNumber(unsigned long number)
{
    if (number < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UptimeCounter::precedingZero(unsigned long number, char* array)
{
    // cleaning char array
    array[0] = '\0';
    char buffer[10] = "";
    // change long to char array
    ltoa(number, buffer, 10);
    if(checkIfOneDigitNumber(number)) strcpy(array, "0");
    strcat(array, buffer);
}