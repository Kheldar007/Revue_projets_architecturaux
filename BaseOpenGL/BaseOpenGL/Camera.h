#pragma once



// Include GLM
#include "glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/transform2.hpp"
#include "glm/gtc/type_ptr.hpp"



class Camera
{
protected:
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
public:
	Camera(float width, float height);
	~Camera();
	
	inline glm::mat4 GetViewMatrix()		{ return m_ViewMatrix; }
	inline glm::mat4 GetProjectionMatrix()	{ return m_ProjectionMatrix; }


	void Update();
	void UpdateProjectionMatrix(float width, float height);

	void translateLocal(float x, float y, float z) { m_ViewMatrix = glm::translate(x, y, z) * m_ViewMatrix; }
	void translateGlobal(float x, float y, float z) { m_ViewMatrix = m_ViewMatrix * glm::translate(x, y, z); }

	void rotateGlobal(float angle, float x, float y, float z) { m_ViewMatrix = m_ViewMatrix * glm::rotate(angle, x, y, z); }
	void rotateLocal(float angle, float x, float y, float z) { m_ViewMatrix = glm::rotate(angle, x, y, z) * m_ViewMatrix; }

	float oldDeltaY;
	float deltaX;
	float deltaY;
	glm::vec3 camera_forward;
	glm::vec3 camera_up;
	glm::vec3 camera_right;
	glm::vec3 eyePosition;


};

