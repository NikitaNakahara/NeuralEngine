cmake_minimum_required(VERSION 3.12)

set(SRC 
    src/Window.cpp
    src/Renderer.cpp
    src/Shader.cpp
    src/Model.cpp
)
set(INCLUDE_DIR include/Graphic)
set(INCLUDE 
    ${INCLUDE_DIR}/Window.hpp
    ${INCLUDE_DIR}/Renderer.hpp
    ${INCLUDE_DIR}/Shader.hpp
    ${INCLUDE_DIR}/Model.hpp
)

add_library(Graphic STATIC ${SRC} ${INCLUDE_DIR})
target_include_directories(Graphic PUBLIC include)

target_link_libraries(Graphic System)

add_subdirectory(../../libs/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(Graphic glfw)

add_subdirectory(../../libs/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(Graphic glad)