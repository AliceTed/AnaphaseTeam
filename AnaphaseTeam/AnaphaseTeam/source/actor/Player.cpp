#include "../../header/actor/Player/Player.h"
#include "../../header/actor/MoveState.h"
#include "../../header/actor/StandState.h"
Player::Player()
	:m_action(nullptr)
{}
Player::~Player()
{}
void Player::initialize()
{
	actionChange(std::make_shared<StandState>());
}
void Player::update(float deltatime)
{
	m_action->action(this);
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
	/*
	* @fn
	* @brief アクションステートの切り替え関数
	* @param (_action) 切り替えるアクションのShared_ptr
	*/
void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}
