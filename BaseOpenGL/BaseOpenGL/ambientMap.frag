#version 330

uniform sampler2D ambientMap;
uniform sampler2D diffuseMap;
uniform sampler2D bumpMap;
uniform vec3 lightAmbient;
uniform vec3 lightDiffuse;
uniform vec3 lightSpecular;

uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;
uniform float shininess;

uniform vec4 lightPosition;

in vec2 uv_out;
in vec3 normal_out;
in vec4 worldPosition;
in vec4 eyePosition;

out vec4 color_final;

void main()
{
	vec4 textureColor = texture2D(diffuseMap, uv_out);

	vec3 ambient = ambientColor * lightAmbient ;

	vec3 lightDir = lightPosition.xyz - (worldPosition.xyz * lightPosition.w) ;
	lightDir = normalize (lightDir) ;
	float lampert = dot (normal_out , lightDir) ;
	vec3 diffuse = diffuseColor * lightDiffuse * max (lampert , 0) ;

	vec3 reflex = reflect (- lightDir , normal_out);
	vec3 v = -normalize (eyePosition.xyz);
	float rv = dot (reflex , v) ;
	float rva = pow (rv , shininess);
	vec3 specular = rva * lightSpecular * specularColor ;

	// color_final = color_out * textureColor;
	color_final = vec4 (ambient , 1) + vec4 (diffuse , 1) + vec4 (specular , 1) ;
	// color_final = vec4 (normal_out,1.0);
	color_final = color_final * textureColor ;
}
