#include "../../header/camera/Camera.h"
//a
Camera::Camera(float range_Position, float range_Eye, const GSvector3 & offset)
	:range_Position(range_Position)
	, range_Eye(range_Eye),
	offset(offset),
	m_near(0.3f),
	m_far(1000.0f)
{
}

Camera::~Camera()
{
}


void Camera::lookAt(const GSvector3& target, float dir)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	position = target;

	GSvector3 t;
	//ό’Δ’ιϋό
	GSvector3 at;

	gsVector3FromEleDir(&at, 0.0f, dir);

	t = at*range_Position;
	position -= t;
	position += offset;

	GSvector3 eyeTarget = target;
	t = at*range_Eye;
	eyeTarget += t;

	gluLookAt(
		position.x, position.y, position.z,/*JΚu*/
		eyeTarget.x, eyeTarget.y, eyeTarget.z,/* _*/
		0.0f, 1.0f, 0.0f/*Jγό«ϋό */
		);
}

const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	//§Ο·sρ
	GSmatrix4 matProj;
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&matProj);
	//μΟ·sρ
	GSmatrix4 matView;
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&matView);

	//δ
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &matView, &matProj);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterΖJΜ£
	float dis = ohter.distance(position);
	//£ΖnearΜ·
	return dis-(m_near+radius);
}
