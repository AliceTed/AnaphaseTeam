#include "../../header/actor/Player/Player.h"
#include "../../header/actor/MoveState.h"
#include "../../header/actor/StandState.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/data/Model_ID.h"
/**
*モデルリソースはコミットしなかったので各自でお願い
*/
Player::Player()
	:Actor(Transform(),MODEL_ID::PLAYER), m_action(nullptr)
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.addAnimation(ANIMATION_ID::STAND,80.f,1.0f,true);
	m_animator.changeAnimation(ANIMATION_ID::STAND);
}
void Player::update(float deltatime)
{
	
	m_action->action(this,deltatime);
	m_animator.update(deltatime);
}
void Player::draw(const Renderer &_renderer)
{
	m_animator.bind();
	_renderer.getDraw3D().drawMesh(MESH_ID::PLAYER,m_transform.getMatrix4());
}
void Player::finish()
{

}
void Player::stand()
{
	m_animator.changeAnimation(ANIMATION_ID::STAND, true);
}
void Player::move()
{

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
