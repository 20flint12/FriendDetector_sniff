#pragma once
#ifndef _MY_NTP_H    // Put these two lines at the top of your file.
#define _MY_NTP_H    // (Use a suitable name, usually based on the file name.)

//https://github.com/arduino-libraries/NTPClient

#include <NTPClient.h>
#include <WiFiUdp.h>


WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 10800, 3600*1000);


uint8_t hour = 0;     // ÑÑÐ°Ð½Ð¸Ñ ÑÐµÐºÑÑÐ¸Ð¹ ÑÐ°Ñ
uint8_t minute = 0;     // ÑÑÐ°Ð½Ð¸Ñ ÑÐµÐºÑÑÐ¸Ðµ Ð¼Ð¸Ð½ÑÑÑ


/*
if(timeClient.isTimeSet()) {
    if (hour == timeClient.getHours() && minute == timeClient.getMinutes()) {
      digitalWrite(led, 0);
    }
  }
*/


String publishNtpTime() {

  String currtime = "";

  int wday = timeClient.getDay();
  switch (wday) {
    case 1:
      currtime += "mon";
      break;
    case 2:
      currtime += "tue";
      break;
    case 3:
      currtime += "wed";
      break;
    case 4:
      currtime += "thu";
      break;
    case 5:
      currtime += "fri";
      break;
    case 6:
      currtime += "sat";
      break;
    case 0:
      currtime += "sun";
      break;
    default:
      currtime += "???";
  }

  currtime += ", " + timeClient.getFormattedTime();
 
  return currtime;
}


#endif // _MY_NTP_H    // Put this line at the end of your file.
