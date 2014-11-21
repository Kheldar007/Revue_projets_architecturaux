#version 330

uniform sampler2D ambientMap;
uniform sampler2D diffuseMap;
uniform sampler2D bumpMap;
uniform vec3 lightAmbient;
uniform vec3 lightDiffuse;
uniform vec3 lightSpecular;

in vec2 uv_out;
in vec4 color_out;
in vec3 normal_out;

out vec4 color_final;

void main()
{
	vec4 textureColor = texture2D(diffuseMap, uv_out); // Pour l'Enterprise.
	// vec4 textureColor = texture2D(ambientMap, uv_out); // Pour l'eglise.

	/*vec4 phong = ambientColor * lightAmbient + ((diffuseColor * (lightPosition *
		normal_out) * lightDiffuse) + (specularColor * ((uv_out * viewMatrix) ^ shininess) * lightSpecular)) ;*/ // - viewMatrix

	color_final = color_out * textureColor;
	// color_final = vec4 (normal_out,1.0);
}
