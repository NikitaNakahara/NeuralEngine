cmake_minimum_required(VERSION 3.12)

set(SRC src/main.cpp src/Application.cpp src/InputManager.cpp)
set(INCLUDE_DIR include/Core)
set(INCLUDE ${INCLUDE_DIR}/Application.hpp ${INCLUDE_DIR}/InputManager.hpp)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} System)
target_link_libraries(${PROJECT_NAME} Graphic)
target_link_libraries(${PROJECT_NAME} X11)
target_link_libraries(${PROJECT_NAME} GL)