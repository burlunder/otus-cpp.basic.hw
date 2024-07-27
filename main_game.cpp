#include "check_value.hpp"
#include "high_scores.hpp"
#include "random_value.hpp"
#include <iostream>
#include <string>

static void show_help(std::string name) {
  std::cerr << "Usage: " << name << " <option(s)>" << "Options:\n"
            << "\t-h, --help\tShow this help message\n"
            << "\t--max <N>\tMax value for random number\n"
            << "\t-t, --table\tShow high_scores table\n"
            << std::endl;
}

int main(int argc, char *argv[]) {
  // process arguments
  if (argc < 1) {
    show_help(argv[0]);
    return 1;
  }
  int arg_max = 100; // Max RND value by default
  bool just_show_table = false;
  for (int i = 0; i < argc; ++i) {
    std::string arg = argv[i];
    // std::cout << "i: " << i << "; arg: " << arg << std::endl; // debug
    if (arg == "-h" || arg == "--help") {
      show_help(argv[0]);
    }
    if (arg == "--max") {
      arg_max = std::stoi(argv[i + 1]); // next argument
    }
    if (arg == "-t" || arg == "--table") {
      just_show_table = true;
    }
  }
  // std::cout << "arg_max: " << arg_max << "\n" << std::endl; // debug
  // std::cout << "show_table: " << show_table << "\n" << std::endl; // debug

  if (!just_show_table) {
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;

    const int random_value = get_random_value(arg_max);
    std::cout << "random_value: " << random_value << "\n" << std::endl; // debug

    int attempts = 0;
    attempts = try_guess_count(random_value);

    std::cout << std::endl;
    high_scores_append(user_name, attempts);
  }

  high_scores_read();

  return 0;
}
