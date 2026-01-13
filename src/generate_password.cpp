#include <string>
#include <random>
#include <algorithm>


struct CharacterSet {
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    
    std::string getAll() const {
        return lowercase + uppercase + digits + symbols;
    }
};


std::string generate_password(int length){
  CharacterSet charset;
  std::random_device rd;
  std::mt19937 generator(rd());

  std::string password;
  
  //убедиться, что все виды символов используются
  std::uniform_int_distribution<int> dist_lower(0, charset.lowercase.size() - 1);
  std::uniform_int_distribution<int> dist_upper(0, charset.uppercase.size() - 1);
  std::uniform_int_distribution<int> dist_digits(0, charset.digits.size() - 1);
  std::uniform_int_distribution<int> dist_symbols(0, charset.symbols.size() - 1);

  password += charset.lowercase[dist_lower(generator)];
  password += charset.uppercase[dist_upper(generator)];
  password += charset.digits[dist_digits(generator)];
  password += charset.symbols[dist_symbols(generator)];

  //добавить оставшиеся к паролю по длине
  std::string all_chars = charset.getAll();
  std::uniform_int_distribution<int> dist_all(0, all_chars.size() - 1);

  while (password.length() < length)
  {
    password += all_chars[dist_all(generator)];
  }
  //перемешивание всех символов в пароле
  std::shuffle(password.begin(), password.end(), generator);
  return password;
}
