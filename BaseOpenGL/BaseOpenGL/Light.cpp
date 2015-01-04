#include "stdafx.h"
#include "Light.h"


Light::Light ()
{
	l_ambient  = glm::vec3 (0.2 , 0.2 , 0.2) ;
	l_diffuse  = glm::vec3 (0.25 , 0.4 , 0.774597) ;
	l_position = glm::vec4 (0.75 , 15 , 0 , 0) ;
	l_specular = glm::vec3 (0.5 , 0.5 , 0.5) ;
}

Light::~Light ()
{
}

void Light::setAmbiant (float a , float b , float c)
{
	l_ambient = glm::vec3 (a , b , c) ;
}
void Light::setDiffuse (float a , float b , float c)
{
	l_diffuse = glm::vec3 (a , b , c) ;
}
void Light::setPosition (float a , float b , float c , float d)
{
	l_position = glm::vec4 (a , b , c , d) ;
}
void Light::setSpecular (float a , float b , float c)
{
	l_specular = glm::vec3 (a , b , c) ;
}