#include "../../header/actor/Player/Player.h"
#include "../../header/actor/MoveState.h"
#include "../../header/actor/StandState.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/data/Model_ID.h"
#include "../../header/device/Input.h"
#include "../../header/camera/Camera.h"
#include "../../header/shape/Ray.h"
#include <gslib.h>
/**
*モデルリソースはコミットしなかったので各自でお願い
*/
const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;
Player::Player(const Input* _input)
	:Actor(Transform(), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0)),
	m_action(nullptr), m_animator(MODEL_ID::PLAYER),
	m_Input(_input) {}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.initialize();
	m_animator.addAnimation(ANIMATION_ID::STAND, 77.f, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::RUN, 78.f, 1.0f, true);
}
void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	m_animator.update(deltatime);
}
void Player::draw(const Renderer& _renderer, const Camera& _camera)
{
	//取りあえず無理やり追従させる
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	if (!isInsideView(_camera))
	{
		return;
	}
	alphaBlend(_camera);
	m_animator.bind();
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform.getMatrix4());
}
void Player::collisionGround(const Map & _map)
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
	//m_Jump.groundHit();

	//mapに埋め込まれていたらy座標を交点に移動
	m_transform.setPositionY(intersect.y);
}
void Player::finish()
{

}
void Player::stand(float deltaTime)
{
	m_animator.changeAnimation(ANIMATION_ID::STAND);
	//if (gsGetKeyState(GKEY_UP) != 0)m_action = std::make_shared<MoveState>();
	move(deltaTime);
}
void Player::move(float deltaTime)
{
	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);

	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*MOVESPEED*deltaTime);

	
	if (gsGetKeyState(GKEY_UP) != 0)m_animator.changeAnimation(ANIMATION_ID::RUN,true);
}
void Player::attack(float deltaTime)
{

}
void Player::damage(float deltaTime)
{

}
void Player::jump(float deltaTime)
{
}
/*
* @fn
* @brief アクションステートの切り替え関数
* @param (_action) 切り替えるアクションのShared_ptr
*/
void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}
