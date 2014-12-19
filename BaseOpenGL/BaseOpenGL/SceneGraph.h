# ifndef SCENEGRAPH_H
# define SCENEGRAPH_H


# include "stdafx.h"


class SceneGraph
{
	protected :
		glm::mat4  modelMatrix ;
		SceneGraph * parentNode ;
	public :
		SceneGraph () ;
		~SceneGraph () ;
		glm::mat4 getModelMatrix () {return modelMatrix ;} ;
} ;


# endif