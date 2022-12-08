#include <Arduino.h>
#include <UptimeCounter.h>

// class initialization
UptimeCounter UpTime;

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(1000);

  Serial.print("DaysPassed = ");
  Serial.println(UpTime.days());

  Serial.print("HoursPassed = ");
  Serial.println(UpTime.hours());

  Serial.print("MinutesPassed = ");
  Serial.println(UpTime.minutes());

  Serial.print("SecoundsPassed = ");
  Serial.println(UpTime.secounds());

  Serial.println(UpTime.uptime());
  Serial.println();

}