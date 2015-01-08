# ifndef SCENEGRAPH_H
# define SCENEGRAPH_H


# include "stdafx.h"
# include "BasicRenderableObject.h"


class SceneGraph
{
	protected :

		SceneGraph *			m_son ;
		BasicRenderableObject *	m_object ;

	public :

		SceneGraph () ;
		~SceneGraph () ;

		BasicRenderableObject * getObject () {return m_object ;}
		BasicRenderableObject * getSon () {return m_son -> getObject () ;}

		void setSon (BasicRenderableObject * object , SceneGraph * son) ; // Ajouter un fils à un noeud.
} ;


# endif