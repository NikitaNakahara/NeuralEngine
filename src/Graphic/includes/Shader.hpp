#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>


GLuint compileShader(int type, const char* path);
GLuint createProgram(GLuint vertex, GLuint fragment);
GLuint createProgram(const char* vertexPath, const char* fragmentPath);
std::string loadShaderSource(const char* path);

void setInt(const char* name, GLuint program, int val);
void setUint(const char* name, GLuint program, unsigned int val);
void setFloat(const char* name, GLuint program, float val);
void setDouble(const char* name, GLuint program, double val);
void setBool(const char* name, GLuint program, bool val);

void setVec2(const char* name, GLuint program, glm::vec2 vec);
void setVec3(const char* name, GLuint program, glm::vec3 vec);
void setVec4(const char* name, GLuint program, glm::vec4 vec);

void setMat4(const char* name, GLuint program, glm::mat4 mat);