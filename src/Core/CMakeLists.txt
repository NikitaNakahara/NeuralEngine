cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Core)

set(SRC_FILES
	src/main.cpp
)

add_executable(${MODULE_NAME} ${SRC_FILES})