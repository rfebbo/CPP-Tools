#include "stringTools.h"
#include "timeTools.h"

/*
stohm
  Description:
    takes seconds and returns a string as hours and minutes
  Parameters:
    sec - an int representing seconds
  Returns:
    string - string formatted as "x hours and x minutes"
*/
std::string stohm(int sec) {
  if (sec <= 0)
    return "";

  int hours = sec / 3600;
  int minutes = (sec / 60) % 60;

  std::string sHours = std::to_string(hours);
  std::string sMinutes = std::to_string(minutes);

  if (hours == 0)
    return (sMinutes + " minutes");

  if (minutes == 0)
    return (sHours + " hours");

  return (sHours + " hours" + " and " + sMinutes + " minutes");
}

/*
toTime
  Description:
    takes a date string in the format "MM/DD/YYYY" and a time string in the
    format "HH:MM" and converts it into ctime's tm structure format
  Parameters:
    dateString – date string in the format "MM/DD/YYYY"
    timeString – time string in the format "HH:MM"
  Returns:
    tm - a structure in the ctime tm struct format
*/
tm toTime(std::string dateString, std::string timeString) {
  int hh, mm, mo, dd, yy;
  tm when = {0};
  try {
    hh = stoi(timeString.substr(0, 2));
    mm = stoi(timeString.substr(3, 2));
    mo = stoi(dateString.substr(0, 2)) - 1;
    dd = stoi(dateString.substr(3, 2));
    yy = stoi(dateString.substr(6, 4)) - 1900;
  } catch (const std::invalid_argument &ia) {
    hh = -1;
    mm = -1;
    mo = -1;
    dd = -1;
    yy = -1;
  }
  when.tm_hour = hh;
  when.tm_min = mm;
  when.tm_mon = mo;
  when.tm_mday = dd;
  when.tm_year = yy;
  when.tm_sec = 0;

  return when;
}

/*
timeValid
  Description:
    recives a tm structure and returns true or false depending on if the date
    is valid.
  Parameters:
    t – a structure in the ctime tm struct format
  Returns:
    bool - true or false depending on if the date is valid.
*/
bool timeValid(tm t) {
  // test for leap year for Feb
  int numDays = isLeapYear(t.tm_year + 1900) ? 29 : 28;
  // check hour, minute, and month for a certain range
  bool validTime = true;

  if ((t.tm_min < 0) || (t.tm_min > 59))
    validTime = false;

  if ((t.tm_hour < 0) || (t.tm_hour > 23))
    validTime = false;

  if ((t.tm_mon < 0) || (t.tm_mon > 11))
    validTime = false;

  switch (t.tm_mon) {
  case 0:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 1:
    if ((t.tm_mday <= 0) || t.tm_mday > numDays)
      validTime = false;
    break;
  case 2:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 3:
    if ((t.tm_mday <= 0) || t.tm_mday > 30)
      validTime = false;
    break;
  case 4:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 5:
    if ((t.tm_mday <= 0) || t.tm_mday > 30)
      validTime = false;
    break;
  case 6:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 7:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 8:
    if ((t.tm_mday <= 0) || t.tm_mday > 30)
      validTime = false;
    break;
  case 9:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  case 10:
    if ((t.tm_mday <= 0) || t.tm_mday > 30)
      validTime = false;
    break;
  case 11:
    if ((t.tm_mday <= 0) || t.tm_mday > 31)
      validTime = false;
    break;
  }

  return validTime;
}

/*
timeString
  Description:
    converts a tm struct into a human readable string format
  Parameters:
    t – a structure in the ctime tm struct format
  Returns:
    string - a string in the format "Mon DD HH:MM YYYY"
*/
std::string timeString(tm t) {
  std::string tString = "";
  switch (t.tm_mon) {
  case 0:
    tString += "Jan ";
    break;
  case 1:
    tString += "Feb ";
    break;
  case 2:
    tString += "Mar ";
    break;
  case 3:
    tString += "Apr ";
    break;
  case 4:
    tString += "May ";
    break;
  case 5:
    tString += "Jun ";
    break;
  case 6:
    tString += "Jul ";
    break;
  case 7:
    tString += "Aug ";
    break;
  case 8:
    tString += "Sep ";
    break;
  case 9:
    tString += "Oct ";
    break;
  case 10:
    tString += "Nov ";
    break;
  case 11:
    tString += "Dec ";
    break;
  }
  tString += numToString(t.tm_mday, 2);
  tString += " " + numToString(t.tm_hour, 2);
  tString += ":" + numToString(t.tm_min, 2);
  tString += " " + std::to_string(t.tm_year + 1900);
  return tString;
}

/*
isLeapYear
  Description:
    determines if a year is a leap year
  Parameters:
    y – an interger representing the year
  Returns:
    bool - true if it is a leap year false otherwise
*/
bool isLeapYear(int y) {
  if (!(y % 4)) {
    if (!(y % 100)) {
      if (!(y % 400))
        return true;
    } else
      return true;
  }
  return false;
}
