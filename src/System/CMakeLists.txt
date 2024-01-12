cmake_minimum_required(VERSION 3.12)

set(SRC src/Log.cpp)
set(INCLUDE_DIR include/System)
set(INCLUDE ${INCLUDE_DIR}/Log.hpp)

add_library(System STATIC ${SRC} ${INCLUDE_DIR})
target_include_directories(System PUBLIC include)