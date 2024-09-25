cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME NeuralEngine)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Utils)
target_link_libraries(${PROJECT_NAME} PUBLIC Utils)
add_subdirectory(Core)
target_link_libraries(${PROJECT_NAME} PUBLIC Core)