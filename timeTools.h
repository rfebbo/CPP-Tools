#pragma once
#include <ctime>
#include <iostream>

std::string stohm(int sec);
tm toTime(std::string, std::string time = "00:00");
bool timeValid(tm);
std::string timeString(tm);
bool isLeapYear(int);
