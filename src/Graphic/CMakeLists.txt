cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Graphic)

set(SRC_FILES
	src/Renderer.cpp
	src/Window.cpp
	src/Shader.cpp
	src/Model.cpp
)

set(INCLUDE_FILES
	includes/Renderer.hpp
	includes/Window.hpp
	includes/Shader.hpp
	includes/Model.hpp
)


add_library(${MODULE_NAME} ${SRC_FILES} ${INCLUDE_FILES})

add_subdirectory(../../libs/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${MODULE_NAME} glfw)

add_subdirectory(../../libs/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${MODULE_NAME} glad)

add_subdirectory(../../libs/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${MODULE_NAME} glm)