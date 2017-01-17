#include "state/enemy/ESlideState.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "actor/Player/Player.h"
#include "math/Random.h"
Goblin::ESlideState::ESlideState(Goblin* _enemy)
	:ActorState(_enemy),m_timer(0.0f)
{

}

void Goblin::ESlideState::start()
{
	Math::Random rnd;
	m_timer.setEndTime(rnd(1, 5));
	if (!m_actor->m_isBlock)m_timer.setEndTime(4);
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKLEFT, true, true);
}

void Goblin::ESlideState::action(float deltaTime)
{
	m_actor->lookAtToPlayer();
	m_timer.update(deltaTime);
	m_actor->m_transform.translate_left(0.03f);
	if (m_timer.isEnd())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Goblin::ESlideState * Goblin::ESlideState::clone() const
{
	return new ESlideState(*this);
}