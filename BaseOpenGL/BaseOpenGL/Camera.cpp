#include "StdAfx.h"
#include "Camera.h"


Camera::Camera(float width, float height)
{
	m_ProjectionMatrix = (glm::mat4)glm::perspective(45.0f, (float)width/(float)height, 0.001f, 1000.0f);

	oldDeltaY = 0.0;

	glm::vec3 eyePosition(0.0f, 0.0f, 0.0f);
	glm::vec3 lookinAtPosition(0.0f, 0.0f, -1.0f);

	camera_right = glm::vec3(1.0f, 0.0f, 0.0f);
	camera_forward = lookinAtPosition - eyePosition;
	camera_forward = glm::normalize(camera_forward);

	glm::vec3 camera_up = glm::cross(camera_right, camera_forward);

	m_ViewMatrix = (glm::mat4)glm::lookAt(eyePosition, lookinAtPosition, camera_up);
}


Camera::~Camera(void)
{
}

void Camera::UpdateProjectionMatrix(float width, float height)
{
	m_ProjectionMatrix = (glm::mat4)glm::perspective(75.0f, (float)width/(float)height, 0.001f, 1000.0f);
}

void Camera::Update()
{
	/*
		// on crée un quat basé sur le vecteur right et l'angle d'élévation (ou tangage)
		glm::quat pitch_quat = glm::angleAxis(deltaX, camera_right);

		// on crée un quat basé sur le vecteur up et l'angle d'azimut (ou lacet)
		glm::quat yaw_quat = glm::angleAxis(deltaY, camera_up);

		// on addition les deux quat
		glm::quat tmp = glm::cross(pitch_quat, yaw_quat);
		tmp = glm::normalize(tmp);

		glm::quat view_quat = glm::quat_cast(m_ViewMatrix);
		glm::normalize(view_quat);

		view_quat = glm::cross(view_quat,tmp);
		glm::normalize(view_quat);

		m_ViewMatrix = glm::mat4_cast(view_quat);*/

	rotateLocal((float)oldDeltaY * -0.5f, 1.0f, 0.0f, 0.0f);
	std::cout << "old: " << oldDeltaY << " et now new:" << deltaY << std::endl;
	deltaY = deltaY+oldDeltaY;
	rotateLocal((float)deltaX * 0.5f, 0.0f, 1.0f, 0.0f);
	rotateLocal((float) (deltaY) * 0.5f, 1.0f, 0.0f, 0.0f);
	
	oldDeltaY = deltaY;
	
}
