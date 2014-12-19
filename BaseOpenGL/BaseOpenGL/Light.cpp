#include "stdafx.h"
#include "Light.h"


Light::Light ()
{
	l_ambient = glm::vec3 (0.5 , 0.5 , 0.5) ;
	l_diffuse = glm::vec3 (0.25 , 0.5 , 1) ;
	l_position = glm::vec4 (0.75 , -0.5 , 0 , 0) ;
	l_specular = glm::vec3 (0.95 , 0.95 , 0.95) ;
}

Light::~Light ()
{
}
