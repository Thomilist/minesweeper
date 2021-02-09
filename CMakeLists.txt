cmake_minimum_required(VERSION 3.10)
project(Minesweeper)

# Main program
add_executable(Minesweeper main.cpp)

# SFML modules
set(SFML_DIR D:\\Programming\\cpp\\libraries\\SFML-2.5.1\\lib\\cmake\\SFML)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics REQUIRED)
target_link_libraries(Minesweeper sfml-graphics)

# Other headers
add_subdirectory(include)
target_link_libraries(Minesweeper Tile)
target_link_libraries(Minesweeper Board)
target_link_libraries(Minesweeper EventHandler)
target_link_libraries(Minesweeper EventLog)
target_link_libraries(Minesweeper MouseAction)