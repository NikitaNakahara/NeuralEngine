cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Core)

set(INCLUDE_PATH include/${MODULE_NAME})
set(SOURCE src/Engine.cpp)
set(INCLUDE ${INCLUDE_PATH}/Engine.hpp)

add_library(${MODULE_NAME} STATIC ${SOURCE} ${INCLUDE})

target_include_directories(${MODULE_NAME} PUBLIC include)

target_link_libraries(${MODULE_NAME} PUBLIC Utils)