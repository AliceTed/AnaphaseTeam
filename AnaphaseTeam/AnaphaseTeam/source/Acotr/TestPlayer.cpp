#include "../../header/actor/TestPlayer.h"

#include "../../header/renderer/Renderer.h"

#include "../../header/device/Input.h"

#include "../../header/camera/Camera.h"
#include "../../header/shape/Ray.h"
TestPlayer::TestPlayer(const Input* _input)
	:Actor(Transform(), Sphere(GSvector3(0, 0, 0), 1)),
	m_Input(_input),
	animation(ANIMATION_ID::KENDO, SKELETON_ID::KENDO, 20,
		AnimationTimer
		(
			gsGetEndAnimationTime(static_cast<GSuint>(ANIMATION_ID::KENDO), 20)), true
		),
	m_Jump()
{
}

TestPlayer::~TestPlayer()
{
}

void TestPlayer::update(float deltatime)
{
	animation.update(deltatime);
	
	m_transform.rotationY(-m_Input->rotate()*deltatime*2);

	float speed(0.3f);
	float dir = -m_transform.getYaw();
	
	GSvector3 forward(m_transform.front()*m_Input->vertical());	
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*speed*deltatime);
	
	sphereChases(GSvector3(0, 1, 0));

	if (m_Input->jumpTrigger())
	{
		m_Jump.start();
	}
	m_Jump.jumping(this,deltatime);
}

void TestPlayer::draw(const Renderer & _renderer, const Camera & _camera)
{
	//取りあえず無理やり追従させる
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	if (!isInsideView(_camera))
	{
		return;
	}
	alphaBlend(_camera);
	animation.bind();
	_renderer.getDraw3D().drawMesh(MESH_ID::KENDO,m_transform);
}

void TestPlayer::collisionGround(const Map & _map)
{
	GSvector3 intersect;
	//現在の位置から下方向のRayを作る
	GSvector3 position = m_transform.getPosition();
	Ray ray(position);
	if (!ray.isCollitionMap(_map, &intersect))
	{
		return;
	}

	if (position.y >= intersect.y)
	{
		return;
	}
	//
	m_Jump.groundHit();

	//mapに埋め込まれていたらy座標を交点に移動
	m_transform.setPositionY(intersect.y);
}

void TestPlayer::jump(float _velocity)
{
	m_transform.translateY(_velocity);
}
