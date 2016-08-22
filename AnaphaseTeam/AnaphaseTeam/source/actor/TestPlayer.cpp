#include "../../header/actor/TestPlayer.h"

#include "../../header/renderer/Renderer.h"

#include "../../header/device/Input.h"

#include "../../header/camera/Camera.h"
#include "../../header/shape/Ray.h"
/*
const float TestPlayer::MOVESPEED=0.3f;
const float TestPlayer::ROTATESPEED = -2.0f;
TestPlayer::TestPlayer(const Input* _input)
	:Actor(Transform(), MODEL_ID::PLAYER,Sphere(GSvector3(0, 0, 0), 1)),
	m_Input(_input),
	animation(ANIMATION_ID::KENDO, SKELETON_ID::KENDO, 20,
		AnimationTimer
		(
			gsGetEndAnimationTime(static_cast<GSuint>(ANIMATION_ID::KENDO), 20)), true
		),
	m_Jump(),
	m_ChainMove()
{
}

TestPlayer::~TestPlayer()
{
}

void TestPlayer::update(float deltatime)
{
	animation.update(deltatime);

	move(deltatime);
	jump(deltatime);
	chain(deltatime);

	sphereChases(GSvector3(0, 1, 0));
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
	_renderer.getDraw3D().drawMesh(MESH_ID::KENDO,m_transform, m_Color);
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

void TestPlayer::move(float deltaTime)
{
	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);

	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*MOVESPEED*deltaTime);
}

void TestPlayer::jump(float deltaTime)
{
	if (m_Input->jumpTrigger())
	{
		m_Jump.start();
	}
	m_Jump.jumping(this, deltaTime);
}

void TestPlayer::chain(float deltaTime)
{
	if (m_Input->chainTrigger())
	{
		m_ChainMove.start();
	}
	m_ChainMove.movement(deltaTime, this);
}

void TestPlayer::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void TestPlayer::chainMove(const GSvector3 & _target,float _time)
{
	//一度加速度にしているが　lerpをそのままsetPosしても良い
	//GSvector3 pos = m_transform.getPosition();
	//GSvector3 velocity = pos.lerp(_target, _time) - pos;
	//m_transform.translate(velocity);
	
	/*
	加速度にすると加算なので外部の影響を受けるが
	代入なら影響を受けない
	//
	m_transform.setPosition(m_transform.getPosition().lerp(_target, _time));
}
*/