

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG     // prints comm exchange
#define APP_DEBUG       // allow custom print or not


typedef uint32_t millis_time_t;

millis_time_t BlynkMillis()
{
    return millis();
}

#define BLYNK_PROGMEM
    #define BLYNK_F(s) s
    #define BLYNK_PSTR(s) s



    #define BLYNK_LOG1(p1)            { BLYNK_LOG_TIME(); BLYNK_PRINT.println(p1); }
    #define BLYNK_LOG2(p1,p2)         { BLYNK_LOG_TIME(); BLYNK_PRINT.print(p1); BLYNK_PRINT.println(p2); }
    #define BLYNK_LOG3(p1,p2,p3)      { BLYNK_LOG_TIME(); BLYNK_PRINT.print(p1); BLYNK_PRINT.print(p2); BLYNK_PRINT.println(p3); }
    #define BLYNK_LOG4(p1,p2,p3,p4)   { BLYNK_LOG_TIME(); BLYNK_PRINT.print(p1); BLYNK_PRINT.print(p2); BLYNK_PRINT.print(p3); BLYNK_PRINT.println(p4); }
    #define BLYNK_LOG6(p1,p2,p3,p4,p5,p6) { BLYNK_LOG_TIME(); BLYNK_PRINT.print(p1); BLYNK_PRINT.print(p2); BLYNK_PRINT.print(p3); BLYNK_PRINT.print(p4); BLYNK_PRINT.print(p5); BLYNK_PRINT.println(p6); }
    #define BLYNK_LOG_IP(msg, ip)     { BLYNK_LOG_TIME(); BLYNK_PRINT.print(BLYNK_F(msg)); \
                                        BLYNK_PRINT.print(ip[0]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.print(ip[1]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.print(ip[2]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.println(ip[3]); }
    #define BLYNK_LOG_IP_REV(msg, ip) { BLYNK_LOG_TIME(); BLYNK_PRINT.print(BLYNK_F(msg)); \
                                        BLYNK_PRINT.print(ip[3]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.print(ip[2]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.print(ip[1]); BLYNK_PRINT.print('.');  \
                                        BLYNK_PRINT.println(ip[0]); }

    static
    void BLYNK_LOG_TIME() {
        BLYNK_PRINT.print('[');
        BLYNK_PRINT.print(BlynkMillis());
        BLYNK_PRINT.print(BLYNK_F("] "));
    }





#if defined(APP_DEBUG)
  #define DEBUG_PRINT(...)  BLYNK_LOG1(__VA_ARGS__)
  #define DEBUG_PRINTF(...)  BLYNK_LOG(__VA_ARGS__)
  #define DEBUG_PRINT1(...)  BLYNK_LOG1(__VA_ARGS__)
  #define DEBUG_PRINT2(...)  BLYNK_LOG2(__VA_ARGS__)
  #define DEBUG_PRINT3(...)  BLYNK_LOG3(__VA_ARGS__)
  #define DEBUG_PRINT4(...)  BLYNK_LOG4(__VA_ARGS__)
#else
  #define DEBUG_PRINT(...)
  #define DEBUG_PRINTF(...)
  #define DEBUG_PRINT1(...)
  #define DEBUG_PRINT2(...)
  #define DEBUG_PRINT3(...)
  #define DEBUG_PRINT4(...)
#endif









