# ifndef SCENEGRAPH_H
# define SCENEGRAPH_H


# include "stdafx.h"


class SceneGraph
{
	protected :
		SceneGraph * nextNode ;
	public :
		SceneGraph () ;
		~SceneGraph () ;
} ;


# endif