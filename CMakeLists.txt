cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project(hello LANGUAGES CXX)

find_package(nlohmann_json REQUIRED)
find_package(aws-lambda-runtime REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "arbre.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC AWS::aws-lambda-runtime nlohmann_json)
aws_lambda_package_target(${PROJECT_NAME})