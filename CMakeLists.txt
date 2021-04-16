cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project(checkers-lambda LANGUAGES CXX)


add_executable(${PROJECT_NAME} "test.cpp" "arbre.cpp")
