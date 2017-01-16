#include "..\..\..\header\state\player\SpecialAttackState.h"
#include "collision/SpecialAttackCollision.h"
Player::SpecialAttackState::SpecialAttackState(Player* _player)
	:ActorState(_player)
{
}

void Player::SpecialAttackState::start()
{
	m_actor->m_animatorOne.changeAnimation(ANIMATION_ID::SPECIALATTACK);
	Collision_Ptr act = std::make_shared<SpecialAttackCollision>(m_actor);
	m_actor->m_collision.add(act);
}

void Player::SpecialAttackState::action(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		changeState(ACTOR_STATE::STAND);
	}
}

Player::SpecialAttackState * Player::SpecialAttackState::clone() const
{
	return new SpecialAttackState(*this);
}
