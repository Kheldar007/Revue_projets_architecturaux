#version 330

in vec3 vertex_in;
in vec3 normal_in;
in vec2 uv_in;

uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec2 uv_out;
out vec3 normal_out;
out vec4 worldPosition;
out vec4 eyePosition;

void main()
{
	worldPosition = modelMatrix * vec4 (vertex_in , 1);
	eyePosition = viewMatrix * worldPosition;
	gl_Position = projectionMatrix * eyePosition;
	uv_out = uv_in;
	normal_out = normal_in ;
}
