cmake_minimum_required(VERSION 3.12)

set(SRC src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} Graphic)