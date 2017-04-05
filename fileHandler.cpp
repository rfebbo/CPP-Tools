#include "fileHandler.h"

/*
fileExists
  Description:
    determines if a file exists according to a given name
  Parameters:
    path - the path to the file
  Returns:
    bool - true if it exists false if not
*/
bool fileExists(std::string path) {
  std::string line;
  std::ifstream file(path);
  if (!file.is_open()) {
    return false;
  }

  return true;
}

/*
getFileSize
  Description:
    determines the number of lines in a file
  Parameters:
    path - the path to the file
  Returns:
    int - the number of lines in a file
*/
int getFileSize(std::string path) {
  std::string line;
  std::ifstream file(path);
  if (!file.is_open()) {
    return -1;
  }
  int index = 0;
  // open the file
  if (file.is_open()) {
    // loop through the file
    while (std::getline(file, line)) {
      // increment the index
      index++;
    }
    file.close();
  }

  return index;
}

/*
readStrings
  Description:
    reads the contents of a file into an array of strings. Each newline is read
    into it's own index in the array
  Parameters:
    path - the path to the file
    strings - the array of strings to fill
  Returns:
    int - the number of lines in a file
*/
void readStrings(std::string path, std::string strings[]) {
  std::string line;
  std::ifstream file(path);
  // open the file
  if (!file.is_open()) {
    std::cout << "Unable to open file\n";
    return;
  }

  if (file.is_open()) {
    int index = 0;
    // loop through the file
    while (std::getline(file, line)) {
      strings[index] = line;
      // increment the index
      index++;
    }
    file.close();
  } else
    std::cout << "Unable to open file\n";
}
