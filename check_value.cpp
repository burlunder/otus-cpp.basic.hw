#include <iostream>

int try_guess_count(const int guess_value) {
  int tries = 0;
  int current_value = 0;

  std::cout << "Enter your guess:" << std::endl;

  do {
    tries += 1;
    std::cin >> current_value;

    if (current_value < guess_value) {
      std::cout << "greater than " << current_value << std::endl;
    } else if (current_value > guess_value) {
      std::cout << "less than " << current_value << std::endl;
    } else {
      std::cout << "you win!" << " attempts = " << tries << std::endl;
      break;
    }

  } while (true);

  return tries;
}
