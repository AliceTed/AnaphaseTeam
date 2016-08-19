#include "../../header/actor/Player/Player.h"
#include "../../header/actor/MoveState.h"
#include "../../header/actor/StandState.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/data/Model_ID.h"
/**
*モデルリソースはコミットしなかったので各自でお願い
*/
Player::Player()
	:Actor(Transform(), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0)),
	m_action(nullptr),m_animator(MODEL_ID::PLAYER)
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.initialize();
	m_animator.addAnimation(ANIMATION_ID::STAND, 77.f, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::RUN, 77.f, 1.0f, true);
}
void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	m_animator.update(deltatime);
}
void Player::draw(const Renderer& _renderer, const Camera& _camera)
{
	m_animator.bind();
	_renderer.getDraw3D().drawMesh(MESH_ID::KENDO, m_transform.getMatrix4());
}
void Player::finish()
{

}
void Player::stand()
{
	m_animator.changeAnimation(ANIMATION_ID::STAND);
	if (gsGetKeyState(GKEY_UP) != 0)m_action = std::make_shared<MoveState>();
}
void Player::move()
{
	m_animator.changeAnimation(ANIMATION_ID::RUN);
	if (gsGetKeyState(GKEY_UP) == 0)m_action = std::make_shared<StandState>();
}
void Player::attack()
{

}
void Player::damage()
{

}
void Player::jump()
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
