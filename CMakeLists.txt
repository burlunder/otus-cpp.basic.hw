cmake_minimum_required(VERSION 3.5)

project(03.homework)

# add_library(
#   random_value OBJECT
#   random_value.cpp
# )

add_executable(
  main_game
  main_game.cpp
  random_value.cpp
  check_value.cpp
  high_scores.cpp
)

# add_library(
#   high_scores STATIC
#   high_scores.cpp
# )
#
# add_library(
#   argument STATIC
#   argument.cpp
# )

set_target_properties(main_game
  PROPERTIES
  CMAKE_CXX_STANDARD 14
  CMAKE_CXX_STANDARD_REQUIRED ON
)
