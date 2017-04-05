#include "ioTools.h"
#include "timeTools.h"

/*
spacer
  Description:
    outputs two sets of 80 hyphens seperated by a newline.
  Parameters:
    none
  Returns:
    none
*/
void spacer(std::string title) {
  for (int i = 0; i < 80; i++) {
    std::cout << '-';
  }
  if (title != "") {
    std::cout << std::endl;
    int spaces = 40 - title.length() / 2;
    for (int i = 0; i < spaces; i++) {
      std::cout << " ";
    }
    std::cout << title;
  }
  std::cout << '\n';
  for (int i = 0; i < 80; i++) {
    std::cout << '-';
  }
  std::cout << '\n';
}

/*
getNum
  Description:
    Prompts for the user a number from a list of numbers then returns the answer
  Parameters:
    nums - an array of numbers
    numNums - the number of numbers in the array
  Returns:
    int - representing the number the user wants
*/
int getNum(int nums[], int numNums) {
  int numberEntered;
  bool invalidInput = true;
  do {
    std::cout << "(";
    for (int i = 0; i < numNums - 1; i++)
      std::cout << nums[i] << ",";
    std::cout << nums[numNums - 1] << "):";
    if (!(std::cin >> numberEntered)) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cout << "INVALID INPUT.\n";
      continue;
    }
    for (int i = 0; i < numNums; i++)
      if (numberEntered == nums[i])
        invalidInput = false;

    if (invalidInput)
      std::cout << "Incorrect number.\n";
  } while (invalidInput);

  std::cin.ignore(256, '\n');

  return numberEntered;
}

/*
getNum
  Description:
    Prompts for the user a number in a certain range then returns the answer
  Parameters:
    low - int representing the low range for input
    high - int representing the high range for inpt
  Returns:
    int - representing the number the user wants
*/
int getNum(int low, int high) {
  int numberEntered;
  do {
    std::cout << "(" << low << "-" << high << "): ";
    if (!(std::cin >> numberEntered)) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cout << "INVALID INPUT.\n";
      continue;
    } else if (numberEntered < low) {
      std::cout << "That number is too LOW.\n";
      continue;
    } else if (numberEntered > high) {
      std::cout << "That number is too HIGH.\n";
      continue;
    } else {
      break;
    }
  } while (true);
  std::cin.ignore(256, '\n');
  return numberEntered;
}

/*
getString:
  Description:
    Prompts the user to enter a string then returns the result.
  Parameters:
    prompt - a string that is used as a prompt for the user to enter a
      string.
Returns:
    string - a string that was entered by the user.
*/
std::string getString(std::string prompt) {
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input);
  return input;
}

/*
  Name:
    ask
  Description:
    prompts the user with a question and returns true or false depending on
    their answer.
  Parameters:
    question - the question to ask.
  Returns:
    A boolean value true for y or false for n.
*/
bool ask(std::string question) {
  bool invalidInput;
  bool result;
  std::string userInput;
  char answer;
  do {
    std::cout << question << std::endl;
    std::getline(std::cin, userInput);
    if (userInput.length() != 1) {
      std::cout << "Please enter a single character.\n";
      invalidInput = true;
      continue;
    }
    // since they entered a single character we can represent it with a
    // character and cast it to lower case
    answer = tolower(userInput[0]);
    switch (answer) {
    case ('y'):
      result = true;
      invalidInput = false;
      break;
    case ('n'):
      result = false;
      invalidInput = false;
      break;
    default:
      std::cout << "Sorry please enter a 'y' or an 'n'.\n";
      invalidInput = true;
    }
  } while (invalidInput);

  return result;
}

/*
  Name:
    getDate
  Description:
    prompts the user for a date "(MM/DD/YYYY): ". If it is valid it returns the
    string in the format "(MM/DD/YYYY): ".
  Parameters:
    p - the question to ask.
  Returns:
    string - string in the format "(MM/DD/YYYY): ".
*/
std::string getDate(std::string p) {
  bool invalidInput = true;
  std::string date;
  while (invalidInput) {
    date = getString(p + "(MM/DD/YYYY): ");
    if (timeValid(toTime(date))) {
      invalidInput = false;
    } else
      std::cout << "Invalid date. Please enter a valid date.(ex. 08/18/1992)\n";
  }

  return date;
}

/*
  Name:
    paragraph
  Description:
    outputs a string and outputs newlines before the limit is reached but not in
    the middle of a word. default limit is 80 char.
  Parameters:
    paragraph - string to outputs
    charIndex - The starting point of the paragraph. default is 0
    limit     - the horizontal limit. default is 80.
  Returns:
    none
*/
void paragraph(std::string paragraph, int charIndex, int limit) {
  // To not go over the 80 character width limit and not cut words
  // in the process
  // charIndex keeps track of where character is being printed in the line
  for (int i = 0; i < paragraph.length(); i++) {

    // just before the start of a word
    if (paragraph[i] == ' ') {
      // perfect place for an endl!
      if (charIndex == limit) {
        charIndex = 0;
        std::cout << std::endl;
        continue;
      }
      // lets see if the word goes past the horizontal
      // limit by looping through it till we hit another space or
      // the end of the string
      int j = 1;
      while ((paragraph[j + i] != ' ') && (i + j) != paragraph.length()) {
        // we need an endlfor this word, and don't want the space at the
        // beginning of the next line so we increment i
        if ((j + charIndex) == limit) {
          std::cout << std::endl;
          charIndex = 0;
          i++;
          break;
        }
        j++;
      }
    }
    // rollover charindex if it hits the limit
    if (charIndex == limit)
      charIndex = 0;
    else
      charIndex++;

    // cout the character of the string
    std::cout << paragraph[i];
  }
  std::cout << std::endl;
}
