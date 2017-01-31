#include "state\enemy\EDownState.h"
#include "data\id\ENEMY_ANIMATION.h"
Goblin::EDownState::EDownState(Goblin* _enemy)
	:ActorState(_enemy), m_timer(0.0f), m_standStart(false), ptr(nullptr)
{

}

void Goblin::EDownState::start()
{
	//bind(指定する関数,対象クラスのポインタ,引数分だけplaceholder)
	ptr = std::bind(&Goblin::EDownState::down, this, std::placeholders::_1);
	m_standStart = false;
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::STANDDYNIG);
	m_timer.initialize();
	m_timer.setEndTime(2.0f);
}

void Goblin::EDownState::action(float deltaTime)
{
	ptr(deltaTime);//std::function呼び出し
	if (m_actor->m_status.getHp() <= 0)
	{
		changeState(ACTOR_STATE::EDEAD);
		m_actor->m_collision.clear();
	}
}

void Goblin::EDownState::stand(float deltaTime)
{
	if (m_actor->m_animatorOne.isEndCurrentAnimation())
	{
		m_actor->m_isDown = false;
		changeState(ACTOR_STATE::ESTAND);
	}
}
void Goblin::EDownState::down(float deltaTime)
{
	m_timer.update(deltaTime);
	if (m_timer.isEnd())
	{
		m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::STAND, 30.f, 1.0f);
		m_standStart = true;
		m_timer.initialize();
		ptr = std::bind(&Goblin::EDownState::stand, this, std::placeholders::_1);
	}
}
Goblin::EDownState * Goblin::EDownState::clone() const
{
	return new EDownState(*this);
}