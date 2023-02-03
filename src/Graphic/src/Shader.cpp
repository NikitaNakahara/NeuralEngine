#include "../includes/Shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include <glm/glm.hpp>

GLuint compileShader(int type, const char* path) {
	GLint success;
	GLchar infoLog[512];

	std::string shaderCode = loadShaderSource(path);

	GLuint shader = glCreateShader(type);
	const char* shaderCodeC = shaderCode.c_str();
	glShaderSource(shader, 1, &shaderCodeC, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		std::string shaderType;
		if (type == GL_VERTEX_SHADER) shaderType = "VERTEX";
		else shaderType = "FRAGMENT";
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" + shaderType + "::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	return shader;
}

GLuint createProgram(GLuint vertex, GLuint fragment) {
	GLint success;
	GLchar infoLog[512];

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
		return 0;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

GLuint createProgram(const char* vertexPath, const char* fragmentPath) {
	GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexPath);
	GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragmentPath);

	return createProgram(vertex, fragment);
}

std::string loadShaderSource(const char* path) {
	std::ifstream shaderFile;
	std::string shaderCode;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		shaderFile.open(path);

		std::stringstream shaderStream;

		shaderStream << shaderFile.rdbuf();

		shaderFile.close();

		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	return shaderCode;
}

// ------- Simple values -------
void setInt(const char* name, GLuint program, int val) {
	glUniform1i(glGetUniformLocation(program, name), val);
}

void setUint(const char* name, GLuint program, unsigned int val) {
	glUniform1ui(glGetUniformLocation(program, name), val);
}

void setFloat(const char* name, GLuint program, float val) {
	glUniform1f(glGetUniformLocation(program, name), val);
}

void setDouble(const char* name, GLuint program, double val) {
	glUniform1d(glGetUniformLocation(program, name), val);
}

void setBool(const char* name, GLuint program, bool val) {
	glUniform1i(glGetUniformLocation(program, name), val);
}

// ------- Vectors -------
void setVec2(const char* name, GLuint program, glm::vec2 vec) {
	glUniform2f(glGetUniformLocation(program, name), vec.x, vec.y);
}

void setVec3(const char* name, GLuint program, glm::vec3 vec) {
	glUniform3f(glGetUniformLocation(program, name), vec.x, vec.y, vec.z);
}

void setVec4(const char* name, GLuint program, glm::vec4 vec) {
	glUniform4f(glGetUniformLocation(program, name), vec.x, vec.y, vec.z, vec.w);
}

// ------- Matrix -------
void setMat4(const char* name, GLuint program, glm::mat4 mat) {
	glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, glm::value_ptr(mat));
}