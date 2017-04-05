#pragma once
#include <iostream>

class Menu {
public:
  Menu(std::string name);
  int runMenu();
  void addItem(std::string item);
  void addItems(std::string items[], int numToAdd);
  int length() {return numItems;};

private:
  std::string menuItems[1000];
  std::string menuName;
  int numItems;
};
