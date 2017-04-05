/*
Name : Rocco Febbo
Program : stringTools
Date : 4/05/2017
Description: Includes various tools for C++ strings.
  Tools are:
    numToString - convert an int to a string puting zeros to fill the width
    fitString - Fit a string to a length
    sToLower - converts a string to lower case

Requirements: string
*/
#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H

#include <string>

std::string numToString(int, int);
std::string fitString(std::string, int);
std::string sToLower(std::string);

#endif /* end of include guard: STRING_TOOLS_H */
