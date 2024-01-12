cmake_minimum_required(VERSION 3.12)

set(SRC src/Window.cpp src/Window.hpp)
set(INCLUDE_DIR include/Graphic)
set(INCLUDE ${INCLUDE_DIR}/Graphic.hpp)

add_library(Graphic STATIC ${SRC} ${INCLUDE_DIR})
target_include_directories(Graphic PUBLIC include)

target_link_libraries(Graphic System)
target_link_libraries(Graphic X11)