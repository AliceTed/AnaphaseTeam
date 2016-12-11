#include"../../../header/state/enemy/EThinkState.h"

Enemy::EThinkState::EThinkState(Enemy* _enemy)
	:ActorState(_enemy)
{

}

void Enemy::EThinkState::start()
{
}

void Enemy::EThinkState::action(float deltaTime)
{
	changeState(ACTOR_STATE::ESTAND);
}

Enemy::EThinkState* Enemy::EThinkState::clone() const
{
	return new EThinkState(*this);
}
