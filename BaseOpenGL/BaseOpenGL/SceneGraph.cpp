# include "stdafx.h"
# include "SceneGraph.h"


SceneGraph::SceneGraph ()
{
	m_son = NULL ; // Racine.
}

SceneGraph::~SceneGraph ()
{
}

void SceneGraph::setSon (BasicRenderableObject * object , SceneGraph * son)
{
	m_son = son ;
	m_object = object ;

	// Mettre a jour la matrice du file.
}