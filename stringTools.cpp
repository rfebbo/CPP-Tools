#include "stringTools.h"

/*
numToString
  Description:
    Recieves an int then converts it to a string puting zeros to fill the
    length
requrements
  Parameters:
    i - int representing the interger recieved
    length - int representing the length of the string returned
  Returns:
    string - string formatted to the requested length
*/
std::string numToString(int i, int length) {
  std::string s;
  int zerosToAdd = length - std::to_string(i).length();

  // if the number is more than 4 digits resize it then return it.
  if (zerosToAdd < 0) {
    s = std::to_string(i);
    s.resize(length);
    return s;
  }

  // add the needed 0s to the string
  for (int i = 0; i < zerosToAdd; i++) {
    s += '0';
  }
  // add the number to the string
  s += std::to_string(i);
  return s;
}

/*
fitString
  Description:
    Recieves a string and a number. The string is returned formatted to fit
    the length.
  Parameters:
    s - string that the user wants to be formatted
    length - int representing the length of the string returned
  Returns:
    string - string formatted to the requested length
*/
std::string fitString(std::string s, int length) {
  if (s.length() <= length)
    return s;
  s.resize(length, ' ');
  return s;
}

/*
sToLower
  Description:
    Recieves a string and returns it in lower case
  Parameters:
    s - string that the user wants to be formatted
  Returns:
    string - lower case string
*/
std::string sToLower(std::string s) {
  std::string lowerS = s;
  for (int i = 0; i < s.length(); i++) {
    lowerS[i] = tolower(s[i]);
  }
  return lowerS;
}
/*
findCommas
  Description:
    Recieves a string and returns the number of commas in it
  Parameters:
    s - string
  Returns:
    int - number of commas
*/
int findCommas(std::string s) {
  int numCommas = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == ',')
      numCommas++;

  return numCommas;
}

/*
csv
  Description:
    Recieves a string and an array of strings and fills the array with the
    values from the first
  Parameters:
    s - string that the user wants to be formatted
    csv - the comma seperated values
  Returns:
    none
*/
void csv(std::string s, std::string csv[]) {
  int valueNum = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ',') {
      valueNum++;
      continue;
    }
    csv[valueNum] += s[i];
  }
}
