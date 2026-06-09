#ifndef MyTimeLibrary_h
#define MyTimeLibrary_h
#endif

#include <ArduinoJson.h>

class MyTimeLibrary
{
public:
  MyTimeLibrary();
  ~MyTimeLibrary();
  void setDebug(bool debug);
  String getFullDateStringAddDelta(bool withTime, int delta);
  tm getTimeWithDelta(int delta);
  String getFullDateStringFromTimeinfo(tm timeinfo, bool withTime);
  
  
protected:
  String getDayOfWeekInFrench(int dayOfWeek);
  String getMonthInFrench(int month);
  bool _debug;
};