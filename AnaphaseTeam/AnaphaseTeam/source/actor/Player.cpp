#include "../../header/actor/Player/Player.h"
#include "../../header/actor/MoveState.h"
#include "../../header/actor/StandState.h"
Player::Player()
	:Actor(Transform(),Sphere(GSvector3(0,0,0),0),Actor_Tag::PLAYER), m_action(nullptr)
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
}
void Player::update(float deltatime)
{
	m_action->action(this,deltatime);
}
void Player::draw()
{

}
void Player::finish()
{

}
void Player::stand()
{

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
