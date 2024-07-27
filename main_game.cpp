#include "check_value.hpp"
#include "high_scores.hpp"
#include "random_value.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  // Ask about name
  std::cout << "Hi! Enter your name, please:" << std::endl;
  std::string user_name;
  std::cin >> user_name;

  const int random_value = get_random_value();

  int attempts = 0;
  attempts = try_guess_count(random_value);

  std::cout << std::endl;
  high_scores_manage(user_name, attempts);

  return 0;
}
