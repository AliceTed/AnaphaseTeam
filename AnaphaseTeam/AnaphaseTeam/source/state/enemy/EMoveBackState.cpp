#include "../../../header/state/enemy/EMoveBackState.h"
#include "../../../header/data/id/ENEMY_ANIMATION.h"
Enemy::EMoveBackState::EMoveBackState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EMoveBackState::start()
{
	//m_timer = 0;
	m_actor->m_animatorOne.changeAnimation(ENEMY_ANIMATION::WALKBACK,true,true);
}

void Enemy::EMoveBackState::action(float deltaTime)
{
	//m_timer += 1 * deltaTime;
	//if (m_timer<50)
	//{
		m_actor->m_transform.translate_front(-0.05f);
		return;
	//}
	//m_actor->changeState(ACTOR_STATE::ESTAND);
}

Enemy::EMoveBackState * Enemy::EMoveBackState::clone() const
{
	return new EMoveBackState(*this);
}