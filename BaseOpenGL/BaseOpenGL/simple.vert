#version 330

in vec3 vertex_in;
in vec3 normal_in;
in vec2 uv_in;

uniform sampler2D diffuseMap;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec2 uv_out;
out vec4 color_out;

void main()
{
	uv_out = uv_in;
	gl_Position = projectionMatrix * viewMatrix * vec4(vertex_in, 1.0);	
}
