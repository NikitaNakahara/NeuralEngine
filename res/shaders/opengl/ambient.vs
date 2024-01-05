#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoords;

out vec3 vColor;
out vec2 vTexCoords;

void main() {
    gl_Position = vec4(position, 1.0);
    vColor = color;
    vTexCoords = texCoords;
}