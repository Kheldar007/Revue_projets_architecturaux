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
		/**
		 * @brief directionalLight Lumiere directionnelle.
		 */
		glm::mat4 directionalLight ;
		/**
		 * @brief positionalLight Lumiere positionnelle.
		 */
		glm::mat4 positionalLight ;
	public :
		/**
		 * @brief Constructeur.
		 */
		Light () ;
		/**
		 * @brief Destructeur.
		 */
		~Light () ;
} ;


# endif

