#include <iostream>
#include <limits>
#include <string>
#include "generate_password.hpp"


#ifdef WIN32
#define SYSTEM_CLEAR "cls"
#else
#define SYSTEM_CLEAR "clear"
#endif // WIN32

using namespace std;

void print_menu(){
  system(SYSTEM_CLEAR);
  cout << "-----------------------PASSWORD_GENERATOR-----------------------" << endl;
  cout << "\n";
}

int main(int argc, char* argv[]){
  int length;
  if (argc > 1) {
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
      cout << "usage:" << endl;
      cout << "program with no given arguments opens an interactive menu" << endl;
      cout << "passgen <length> - generates password with the given number of characters (1-32)\n\n";
      return 0;
    }
    length = atoi(argv[1]);
    if (length > 0 && length <= 32) {
      cout << argv[1] << endl;
      cout << generate_password(length) << endl;
      return 0;
    } else cout << "max length is 32 symbols" << endl; return 0;
  }
  while (true) {
    print_menu();
    cout << "Choose password length (between 12 and 32): ";
    cin >> length;
    if (std::cin.fail()) 
    {
      std::cout << "Error. Please input a number\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      system("sleep 2");
    }
    else if (length < 12 || length > 32) {
      std::cout << "Error: Enter a number between 12 and 32\n";
      system("sleep 2");
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Your password: " << generate_password(length) << endl;
      break;
    }
  }
  
  return 0;
}
