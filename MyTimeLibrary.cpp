#include "MyTimeLibrary.h"


MyTimeLibrary::MyTimeLibrary()
{
    _debug = false;
}

MyTimeLibrary::~MyTimeLibrary()
{
}

void MyTimeLibrary::setDebug(bool debug) {
    _debug =debug;
}

String MyTimeLibrary::getDayOfWeekInFrench(int dayOfWeek)
{
  const char *daysFrench[] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"};
  return daysFrench[dayOfWeek % 7]; // Use modulo just in case
}

String MyTimeLibrary::getMonthInFrench(int month)
{
  const char *monthsFrench[] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Juin", "Juil", "Aou", "Sep", "Oct", "Nov", "Dec"};
  return monthsFrench[(month - 1) % 12]; // Use modulo and adjust since tm_mon is [0,11]
}

String MyTimeLibrary::getFullDateStringAddDelta(bool withTime, int delta)
{
  struct tm timeinfo = getTimeWithDelta(delta);
  String dayOfWeek = getDayOfWeekInFrench(timeinfo.tm_wday);
  String month = getMonthInFrench(timeinfo.tm_mon + 1); // tm_mon is months since January - [0,11]
  char dayBuffer[3];
  snprintf(dayBuffer, sizeof(dayBuffer), "%02d", timeinfo.tm_mday);

  String result = dayOfWeek + " " + String(dayBuffer) + " " + month;
  if (withTime)
  {
    char timeBuffer[9];
    snprintf(timeBuffer, sizeof(timeBuffer), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    result = result + " " + String(timeBuffer);
  }
  return result;
}

tm MyTimeLibrary::getTimeWithDelta(int delta)
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Echec de récupération de la date !");
    timeinfo = {0};
  }

  timeinfo.tm_mday += delta;
  mktime(&timeinfo);
  return timeinfo;
}
