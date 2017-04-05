/*
Name : Rocco Febbo
Program : ioTools
Date : 4/05/2017
Description: Includes various tools for the terminal interface(CLI).
  Tools are:
    spacer - place a spacer with optional title and width
    getNum - get a number in a range or from a list of numbers(int)
    getString - get a string after a prompt
    ask - get an answer to a yes or no question
    paragraph - output a string with a width limit without cutting up words
    getDate - get a valid date
    getValidPath - get a vaild path to a file

Requirements: iostream, fileHandler, stringTools, timeTools
*/
#ifndef IO_TOOLS_H
#define IO_TOOLS_H

#include <iostream>

void spacer(std::string title = "", int width = 80);
int getNum(int[], int);
int getNum(int, int);
std::string getString(std::string);
bool ask(std::string);
void paragraph(std::string, int charIndex = 0, int limit = 80);
std::string getDate(std::string p = "");
std::string getValidPath();

#endif /* end of include guard: IO_TOOLS_H */
