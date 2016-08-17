#include "../../header/actor/TestPlayer.h"

#include "../../header/renderer/Renderer.h"

#include "../../header/device/Input.h"

#include "../../header/math/Calculate.h"
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
	jumpPower(0),
	jump(JUMPSTATE::Non)
{
}

TestPlayer::~TestPlayer()
{
}

void TestPlayer::update(float deltatime)
{
	animation.update(deltatime);
	float speed(0.5f);

	m_transform.rotationY(-m_Input->horizontal()*deltatime);

	float dir = m_transform.getYaw();
	Math::Sin sin;
	Math::Cos cos;
	GSvector3 vel(sin(dir), 0, cos(dir));
	vel *= m_Input->vertical()*speed*deltatime;
	m_transform.translate(vel);
	sphereChases(GSvector3(0, 1, 0));

	if (m_Input->upTrigger()&&jump!=JUMPSTATE::SecondStep)
	{
		if (jump == JUMPSTATE::Non)
		{
			jumpPower = 1.5;
			jump = JUMPSTATE::FristStep;
		}
		else if (jump==JUMPSTATE::FristStep)
		{
			jumpPower = 1.4f;
			jump = JUMPSTATE::SecondStep;
		}
	}
	if (jump!=JUMPSTATE::Non)
	{
		m_transform.translateY(jumpPower*deltatime);
		Math::Clamp clamp;
		jumpPower = clamp(jumpPower - 0.1f, -2.0f,2.0f);
	}
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
	jump = JUMPSTATE::Non;
	//mapに埋め込まれていたらy座標を交点に移動
	m_transform.setPositionY(intersect.y);
}
