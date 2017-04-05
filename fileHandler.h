#pragma once
#include <fstream>
#include <iostream>

// protoypes
bool fileExists(std::string);
int getFileSize(std::string);
void readStrings(std::string, std::string[]);
std::string getValidPath();
