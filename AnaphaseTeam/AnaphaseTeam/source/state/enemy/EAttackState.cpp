#include "state/enemy/EAttackState.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "math/Random.h"
Goblin::EAttackState::EAttackState(Goblin* _enemy)
	:ActorState(_enemy), m_secoundAttack(), m_timer(0.0f), m_attack(false)
{
}

void Goblin::EAttackState::start()
{
	m_attack = false;
	m_timer.initialize();
	m_timer.setEndTime(0.8f);
	m_actor->lookAtToPlayer();//プレイヤーの方向を見る
	//m_actor->m_transform.translate_front(0.5);
	Math::Random rnd;
	m_secoundAttack = rnd(0, 10) == 0 ? true : false;//二段攻撃をするか
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK1);
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENEMY_ATTACK);
}

void Goblin::EAttackState::action(float deltaTime)
{
	m_timer.update(deltaTime);
	if (m_timer.isEnd())
	{
		collisionStart();
	}
	else{ m_actor->m_transform.translate_front(0.007f); }
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		GameDevice::getInstacnce().sound().stopSE(SE_ID::ENEMY_ATTACK);
		ACTOR_STATE next;
		next = m_secoundAttack ? ACTOR_STATE::ESECOUNDATTACK : ACTOR_STATE::ETHINK;

		m_actor->changeState(next);
	}
}
void Goblin::EAttackState::collisionStart()
{
	if (m_attack)return;
	m_actor->createAttackCollision();
	m_attack = true;
}
Goblin::EAttackState * Goblin::EAttackState::clone() const
{
	return new EAttackState(*this);
}
