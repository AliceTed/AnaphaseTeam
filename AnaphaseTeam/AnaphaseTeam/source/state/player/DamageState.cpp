#include"state/player/DamageState.h"
#include "data/id/ANIMATION_ID.h"
Player::DamageState::DamageState(Player* _player)
	:ActorState(_player)
{
}

void Player::DamageState::start()
{
	m_actor->m_animatorOne.changeAnimationLerp(static_cast<GSuint>(ANIMATION_ID::DAMAGE),2.0f);
	GameDevice::getInstacnce().sound().playSE(SE_ID::PLAYER_STEP);
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
		GameDevice::getInstacnce().sound().stopSE(SE_ID::PLAYER_STEP);
		changeState(ACTOR_STATE::STAND);
	}
}
Player::DamageState* Player::DamageState::clone() const
{
	return new DamageState(*this);
}