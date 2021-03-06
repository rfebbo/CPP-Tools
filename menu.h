/*
Name : Rocco Febbo
Program : menu
Date : 4/05/2017
Description: A class for maintaining a menu in a CLI.
Requirements: iostream, ioTools
*/
#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu {
public:
  Menu(std::string name);
  int runMenu();
  void addItem(std::string item);
  void addItems(std::string items[], int numToAdd);
  int length() { return numItems; };
  void disableItem(int);
  void enableItem(int);
  void editItem(int, std::string);
  int numEnabled();

private:
  struct item_t {
    std::string name;
    int index;
    bool enabled;
  };
  item_t menuItems[1000];
  std::string menuName;
  int numItems;
};

#endif /* end of include guard: MENU_H */
