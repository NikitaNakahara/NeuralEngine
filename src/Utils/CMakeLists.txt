cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Utils)

set(INCLUDE_PATH include/${MODULE_NAME})
set(SOURCE src/Logger.cpp)
set(INCLUDE 
	${INCLUDE_PATH}/Logger.hpp
	${INCLUDE_PATH}/Log.hpp
)

add_library(${MODULE_NAME} STATIC ${SOURCE} ${INCLUDE})

target_include_directories(${MODULE_NAME} PUBLIC include)