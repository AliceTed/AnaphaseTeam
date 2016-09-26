#include "../../header/camera/Camera.h"

Camera::Camera(void) :
	m_perspective(Perspective()),
	m_look_at(LookAt())
{

}

Camera::Camera(const Perspective* _perspective, const GSvector3* _position) :
	m_perspective(*_perspective),
	m_look_at(LookAt(_position, &(*_position + GSvector3(0, 0, -1)), &GSvector3(0, 1, 0)))
{
}

Camera::Camera(float range_Position, float range_Eye, const GSvector3 & offset) :
	m_perspective(Perspective(45.0f, 800.0f / 600.0f, 0.3f, 1000.0f)),
	m_look_at(LookAt(&GSvector3(0, 0, 0), &GSvector3(0, 0, 0), &GSvector3(0, 1, 0))),
	range_Position(range_Position), 
	range_Eye(range_Eye),
	offset(offset)
{
}

Camera::~Camera()
{
}

void Camera::update(void)
{
	update_perspective(&m_perspective);

	update_look_at(&m_look_at);

	return;
}

void Camera::move(const GSvector3* _position)
{
	m_look_at.position = *_position;

	return;
}

void Camera::look_at(const GSvector3* _target)
{
	m_look_at.target = *_target;

	return;
}

void Camera::lookAt(const GSvector3& target, float dir)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	position = target;

	GSvector3 t;
	//向いている方向
	GSvector3 at;

	gsVector3FromEleDir(&at, 0.0f, dir);

	t = at*range_Position;
	position -= t;
	position += offset;

	GSvector3 eyeTarget = target;
	t = at*range_Eye;
	eyeTarget += t;

	gluLookAt(
		position.x, position.y, position.z,/*カメラ位置*/
		eyeTarget.x, eyeTarget.y, eyeTarget.z,/* 注視点*/
		0.0f, 1.0f, 0.0f/*カメラ上向き方向 */
		);
}

const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	//透視変換行列
	GSmatrix4 matProj;
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&matProj);
	//視野変換行列
	GSmatrix4 matView;
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&matView);

	//視錐台
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &matView, &matProj);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterとカメラの距離
	float dis = ohter.distance(position);
	//距離とnearの差
	return dis-(m_perspective.near+radius);
}

const float Camera::distance(const GSvector3 & ohter) const
{
	return position.distance(ohter);
}

const Transform Camera::transform() const
{
	//yaw回転だけ
 	GSvector3 vec=m_look_at.target - m_look_at.position;
	return Transform(position,GSvector3(0,vec.getYaw(),0));
}

void Camera::update_perspective(const Perspective* _perspective) const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
		_perspective->fov,
		_perspective->aspect,
		_perspective->near,
		_perspective->far);

	return;
}

void Camera::update_look_at(const LookAt* _look_at) const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		_look_at->position.x, _look_at->position.y, _look_at->position.z,
		_look_at->target.x, _look_at->target.y, _look_at->target.z,
		_look_at->up.x, _look_at->up.y, _look_at->up.z);

	return;
}