#include"../../../header/state/player/DamageState.h"
#include "../../../header/data/ANIMATION_ID.h"
Player::DamageState::DamageState(Player* _player)
	:ActorState(_player)
{
}

void Player::DamageState::start()
{
	m_actor->m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::DAMAGE), false);
}
void Player::DamageState::action(float deltaTime)
{
	//そもそもスーパーアーマーならダメージステートに行かない
	/*if (m_actor->m_SpecialSkillManager.isSuperArmor())
	{
		actionChange(m_currentAction);
		return;
	}*/

	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		changeState(ACTOR_STATE::STAND);
	}
}
Player::DamageState* Player::DamageState::clone() const
{
	return new DamageState(*this);
}