/*
Name : Rocco Febbo
Program : fileHandler
Date : 4/05/2017
Description: Includes various tools for fileIO.
  Tools are:
    fileExists - check if a file exists
    getFileSize - getting the number of lines in a file
    readStrings - reading the contents of a file into an array of strings

Requirements: fstream, iostream
*/
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <iostream>

// protoypes
bool fileExists(std::string);
int getFileSize(std::string);
void readStrings(std::string, std::string[]);

#endif /* end of include guard: FILE_HANDLER_H */
