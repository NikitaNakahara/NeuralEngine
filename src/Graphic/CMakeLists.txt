cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Graphic)

set(SRC_FILES
	src/Renderer.cpp
	src/Window.cpp
)

set(INCLUDE_FILES
	includes/Renderer.hpp
	includes/Window.hpp
)


add_library(${MODULE_NAME} ${SRC_FILES} ${INCLUDE_FILES})

add_subdirectory(../../libs/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${MODULE_NAME} glfw)