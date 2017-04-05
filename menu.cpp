#include "ioTools.h"
#include "menu.h"

Menu::Menu(std::string name) {
  numItems = 0;
  menuName = name;
}

/*
runMenu
  Description:
    Displays the main menu and gets a response and returns it
  Parameters:
    none
  Returns:
    int - number response ranging from 1 to the number of Items in the menu
      object
*/
int Menu::runMenu() {
  spacer(menuName);
  for (int i = 0; i < numItems; i++) {
    std::cout << i + 1 << ")" << menuItems[i] << std::endl;
  }

  return getNum(1, numItems);
}

/*
addItem
  Description:
    Adds an item to the list of items
  Parameters:
    item - string representing an item
  Returns:
    none
*/
void Menu::addItem(std::string item) {
  menuItems[numItems] = item;
  numItems++;
}

/*
addItems
  Description:
    Adds a list of items to the list of items in the class
  Parameters:
    items - an array of strings representing a items to add to the menu
  Returns:
    none
*/
void Menu::addItems(std::string items[], int numToAdd) {
  for (int i = 0; i < numToAdd; i++) {
    menuItems[numItems] = items[i];
    numItems++;
  }
}
