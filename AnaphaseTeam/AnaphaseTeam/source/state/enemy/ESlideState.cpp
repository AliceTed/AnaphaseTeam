#include "../../../header/state/enemy/ESlideState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/math/Random.h"
Enemy::ESlideState::ESlideState(Enemy* _enemy)
	:ActorState(_enemy),m_timer(0.0f)
{

}

void Enemy::ESlideState::start()
{
	Math::Random rnd;
	m_timer.setEndTime(rnd(1, 5));
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKLEFT, true, true);
}

void Enemy::ESlideState::action(float deltaTime)
{
	m_timer.update(deltaTime);
	m_actor->m_transform.translate_left(0.03f);
	if (m_timer.isEnd())
	{
		m_actor->changeState(ACTOR_STATE::ETHINK);
	}
}

Enemy::ESlideState * Enemy::ESlideState::clone() const
{
	return new ESlideState(*this);
}