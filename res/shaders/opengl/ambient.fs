#version 330 core

out vec4 fragColor;

in vec2 vTexCoords;

uniform sampler2D container;

void main() {
	fragColor = texture(container, vTexCoords);
}