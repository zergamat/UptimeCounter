# UptimeCounter

Library for arduino like boards.  
Simple, not accurate uptime counter based on millis(). Counts beyound rollovers.

Released under MIT License.

## How to use
Pseudocode
```
#include <UptimeCounter.h>
...
UptimeCounter UpTime;
...
void setup() {
...
}

void loop() {
  delay(1000);
  ...
  Serial.println(UpTime.days());
  Serial.println(UpTime.hours());
  Serial.println(UpTime.minutes());
  Serial.println(UpTime.secounds());
  Serial.println(UpTime.uptime());
  ...
  UpTime.update();
}
```

Example print on serial monitor:
  3
  81
  4879
  292763
  3d 09:19:23
