/**
 * @file    Light.h
 * @author  Nicolas Brunnemer, Isabelle Muller
 */


# ifndef LIGHT_H
# define LIGHT_H


# include "stdafx.h"


/**
 * @class Light Definir les lumieres directionnelles et positionnelles.
 */
class Light
{
	protected :
		glm::vec3 l_ambiant;
		glm::vec3 l_diffuse;
		glm::vec3 l_specular;
		float	  l_shininess;
		glm::vec4 l_position; // Si w = 0 : source directionnelle , si w = 1 : source positionnelle.
	public :
		Light  () ;
		~Light () ;
		glm::vec4 getAmbiant()  {return l_ambiant;}
		glm::vec4 getDiffuse()  {return l_diffuse;}
		glm::vec4 getPosition() {return l_position;}
		glm::vec4 getSpecular() {return l_specular;}
} ;


# endif

