#pragma once
#ifndef _MY_TIMERS_H    // Put these two lines at the top of your file.
#define _MY_TIMERS_H    // (Use a suitable name, usually based on the file name.)

#include <arduino-timer.h>  // https://github.com/contrem/arduino-timer


auto timerMainSniff = timer_create_default();
//Timer<1, millis, void *> timerMainSniff;
Timer<>::Task taskMainSniff;

auto timerPrintSniff = timer_create_default();
//Timer<1, millis, void *> timerPrintSniff;
Timer<>::Task taskPrintSniff;

auto timerBleReceived = timer_create_default();
Timer<>::Task taskBleReceived;



#define PERIOD_MainSniff  500                           // 500 ms 
#define PERIOD_PrintSniff 30 * 1000                     // 30 s
#define PERIOD_BleReceived 100                          // 100 s

// #define PERIOD_ModeSniff  PERIOD_PrintSniff * 3 + 700   // 3 times + 1 s
// #define PERIOD_ModeBot    PERIOD_PrintBot * 2 + 3000    // 2 times + 1 s



String publishSystemUptime2() {

//   uptime::calculateUptime();  

  char ut[60];
//   snprintf(ut, sizeof(ut), "%d days %02d:%02d:%02d", uptime::getDays(), uptime::getHours(), uptime::getMinutes(), uptime::getSeconds());

  return String(ut);
}

  
void launch_tasksSniff(void)
{
    taskMainSniff = timerMainSniff.in(1, procMainSniff);
    taskPrintSniff = timerPrintSniff.in(PERIOD_PrintSniff, procPrintSniff);  
}


void recharge_taskMainSniff(void)
{
    taskMainSniff = timerMainSniff.in(PERIOD_MainSniff, procMainSniff);
}


void recharge_taskPrintSniff(void)
{
    taskPrintSniff = timerPrintSniff.in(PERIOD_PrintSniff, procPrintSniff);
}


void recharge_taskBleReceived(void)
{
    taskBleReceived = timerBleReceived.in(PERIOD_BleReceived, procPrintSniff);
}



#endif // _MY_TIMERS_H    // Put this line at the end of your file.
