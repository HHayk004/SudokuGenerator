cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add your source files here
set(SOURCES 
    ./main.cpp
    ./SudokuGenerator.cpp
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES})
