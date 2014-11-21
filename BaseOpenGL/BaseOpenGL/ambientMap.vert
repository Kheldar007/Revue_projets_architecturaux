#version 330

in vec3 vertex_in;
in vec3 normal_in;
in vec2 uv_in;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;
uniform float shininess;
uniform vec4 lightPosition;

out vec2 uv_out;
out vec4 color_out;
out vec3 normal_out;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * vec4(vertex_in, 1.0);
	color_out = vec4(diffuseColor, 1.0);
	uv_out = uv_in;
	normal_out = normal_in;
}
