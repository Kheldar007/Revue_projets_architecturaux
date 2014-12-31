# ifndef LIGHT_H
# define LIGHT_H


# include "stdafx.h"


/**
 * @class Light Definir les lumieres directionnelles et positionnelles.
 */
class Light
{
	protected :
		glm::vec3 l_ambient;
		glm::vec3 l_diffuse;
		glm::vec3 l_specular;
		glm::vec4 l_position; // Si w = 0 : source directionnelle , si w = 1 : source positionnelle.
	public :
		Light  () ;
		~Light () ;
		glm::vec3 getAmbient()   {return l_ambient;}
		glm::vec3 getDiffuse()   {return l_diffuse;}
		glm::vec4 getPosition()  {return l_position;}
		glm::vec3 getSpecular()  {return l_specular;}
		void setAmbiant (float a , float b , float c) ;
		void setDiffuse (float a , float b , float c) ;
		void setPosition (float a , float b , float c , float d) ;
		void setSpecular (float a , float b , float c) ;
} ;


# endif

