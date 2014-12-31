#ifndef VBO_OBJECT_H
#define VBO_OBJECT_H

#include "stdafx.h"
# include "Light.h"
#include "ShaderProgram.h"
#include "ObjectMaterial.h"




class BasicRenderableObject
{
protected :
	GLuint							m_Vao;

	GLuint							m_VBOPosition;
	GLuint							m_VBONormal;
	GLuint							m_VBOTexCoord;
	std::vector<GLuint>				m_SubObjectsVBOTriangles;
	
	GLuint							m_NumberOfSharedVertices;
	GLuint							m_NumberOfSharedNormals;
	GLuint							m_NumberOfSharedTexCoords;
	std::vector<GLuint>				m_SubObjectsNumberOfTriangles;

	GLfloat*						m_Positions;
	GLfloat*						m_Normals;
	GLfloat*						m_TexCoords;
	std::vector<GLuint*>			m_SubObjectsIndexes;

	ShaderProgram*					m_ShaderProgram;

	int								m_CurrentMaterial;
	std::vector<ObjectMaterial*>	m_Materials;

	glm::mat4						m_ModelMatrix;
	
public :
	BasicRenderableObject() { } ;
	~BasicRenderableObject();

	void init();
	void initShader(ShaderProgram* shaderProgram);
	void loadMtl(char *filename);
	void loadObj(char *filename);
	void addSubObject(std::vector<GLuint>& faceIndexes);
	void setCurrentMaterial(const char* line);
	void fillInVBO();
	void createVertexArrayObject();

	void translateLocalObject(float x, float y, float z) { m_ModelMatrix = glm::translate(x, y, z) * m_ModelMatrix; }
	void translateGlobalObject(float x, float y, float z) { m_ModelMatrix = m_ModelMatrix * glm::translate(x, y, z); }

	void rotateGlobalObject(float angle, float x, float y, float z) { m_ModelMatrix = m_ModelMatrix * glm::rotate(angle, x, y, z); }
	void rotateLocalObject(float angle, float x, float y, float z) { m_ModelMatrix = glm::rotate(angle, x, y, z) * m_ModelMatrix; }

	glm::mat4 getModelMatrix () {return m_ModelMatrix ;}

	virtual void draw(glm::mat4	modelMatrix , glm::mat4	viewMatrix, glm::mat4 projectionMatrix, Light * light);

	std::vector<GLuint> getSubObjectsVBOTriangles () {return m_SubObjectsVBOTriangles ;}
} ;

#endif
