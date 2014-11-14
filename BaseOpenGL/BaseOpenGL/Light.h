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
		glm::vec3 ambient ;
		glm::vec3 diffuse ;
		glm::vec3 specular ;
		float	  shininess ;
		glm::vec4 position ; // Si w = 0 : source directionnelle , si w = 1 : source positionnelle.
	public :
		Light () ;
		~Light () ;
		glm::vec4 getPosition () {return position ;}
} ;


# endif

