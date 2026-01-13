/* Генератор паролей на C++
 * 
 * Реализация:
 * 1. использовать std::random_device + std::mt19937 для генерации рандомных значений (done)
 * 2. использовать все символы английского алфавита большие и маленькие, цифры и спецсимволы (done)
 * 3. убедиться что все виды символов есть в создаваемом пароле (done)
 * 4. создать пароль определенной длины миннимум в 12 символов (done)
 * 5. запросить от пользователя длину пароля (done)
 */

#include <iostream>
#include <limits>
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

int main(){
  int length;
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
