/*
Name : Rocco Febbo
Program : stringTools
Date : 4/05/2017
Description: Includes various tools for ctime.
  Tools are:
    itohm - Convert seconds into hours and minutes in string type
    toTime - Convert a string into a tm struct
    timeValid - test a tm struct for validity
    timeString - convert a tm struct to a string
    isLeapYear - test a year(int) if it is a leap year

Requirements: string, ctime, stringTools
*/
#ifndef TIME_TOOLS_H
#define TIME_TOOLS_H

#include <ctime>
#include <string>

std::string itohm(int sec);
tm toTime(std::string, std::string time = "00:00");
bool timeValid(tm);
std::string timeString(tm);
bool isLeapYear(int);

#endif /* end of include guard: TIME_TOOLS_H */
