cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Core)

set(SRC_FILES
	src/main.cpp
	src/Application.cpp
	src/Log.cpp
)

set(INCLUDE_FILES
	src/Application.hpp
	src/Log.hpp
)

add_executable(${MODULE_NAME} ${SRC_FILES} ${INCLUDE_FILES})

target_link_libraries(${MODULE_NAME} Graphic)