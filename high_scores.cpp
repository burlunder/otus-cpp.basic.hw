#include <fstream>
#include <iostream>
#include <string>

void high_scores_append(std::string user_name, int attempts) {

  const std::string high_scores_filename = "high_scores.txt";

  // It means there were no guess game if attempts == 0
  if (attempts > 0) {
    // Write new high score to the records table
    // We should open the output file in the append mode - we don't want
    // to erase previous results.
    std::ofstream out_file(high_scores_filename, std::ios_base::app);
    if (!out_file.is_open()) {
      std::cout << "Failed to open file for write: " << high_scores_filename
                << "!" << std::endl;
    }

    // Append new results to the table:
    out_file << user_name << ' ';
    out_file << attempts;
    out_file << std::endl;
  }
}

// Read the high score file and print all results
void high_scores_read() {

  const std::string high_scores_filename = "high_scores.txt";

  std::ifstream in_file(high_scores_filename);
  if (!in_file.is_open()) {
    std::cout << "Failed to open file for read: " << high_scores_filename << "!"
              << std::endl;
  }

  std::cout << "High scores table:" << std::endl;

  std::string username;
  int high_score = 0;
  while (true) {
    // Read the username first
    in_file >> username;
    // Read the high score next
    in_file >> high_score;
    // Ignore the end of line symbol
    in_file.ignore();

    if (in_file.fail()) {
      break;
    }

    // Print the information to the screen
    std::cout << username << '\t' << high_score << std::endl;
  }
}
