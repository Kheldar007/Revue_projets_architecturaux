#version 330

uniform sampler2D diffuseMap;
uniform sampler2D ambientMap;
uniform vec3 diffuseColor;

in vec2 uv_out;
in vec4 ;

out vec4 color_final;

void main()
{
	vec4 textureColorDiffuse = texture2D(diffuseMap, uv_out);
	vec4 textureColorAmbient = texture2D(ambientMap, uv_out);
	color_final = diffuseColor * textureColorDiffuse * textureColorAmbient;
}
