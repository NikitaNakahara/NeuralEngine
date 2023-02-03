#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>
#include <iostream>

class Model {
public:
	void create(GLfloat vertices[], int size, GLuint indices[], int iSize, int verticesCount);
	void draw();

	GLuint getShader() { return shader; }

	void setShader(GLuint _shader) { shader = _shader; }

private:
	GLuint VAO;
	GLuint shader;

	int verticesCount;
};