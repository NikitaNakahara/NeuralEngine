#version 330 core

out vec4 fragColor;

in vec3 vColor;
in vec2 vTexCoords;

uniform sampler2D container;

void main() {
	fragColor = texture(container, vTexCoords) * vec4(vColor, 1.0f);
}