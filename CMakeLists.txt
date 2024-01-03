cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME NeuralEngine)

project(${PROJECT_NAME})

add_subdirectory(src/System)
add_subdirectory(src/Graphic)
add_subdirectory(src/Core)

file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})