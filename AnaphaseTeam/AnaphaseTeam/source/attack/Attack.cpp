#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
Attack::Attack(const AttackStatus & _status, ANIMATION_ID _animation, Combo _Qnext, Combo _Snext)
	:m_status(_status), m_Animation(_animation), m_nextQCombo(_Qnext),m_nexySCombo(_Snext)
{
}
Attack::~Attack()
{

}
void Attack::initialize(Player* _player)
{
	motion(_player);
	_player->createAttackCollision();
}

void Attack::update(float deltaTime, Player * _player)
{
	motion(_player);
}
void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}
void Attack::changeMotion(AnimatorOne & _animator, float _speed)
{
	_animator.changeAnimation(static_cast<GSuint>(m_Animation),false, false, false,10.0f, _speed);
}
const bool Attack::isNextAttack(const AnimatorOne & _animator) const
{
	float end = _animator.getCurrentAnimationEndTime();
	float current = _animator.getCurrentAnimationTime();
	float limit = 25.0f;
	return (end - limit) <= current;
}
const bool Attack::isEndMotion(const AnimatorOne & _animator) const
{
	return _animator.isEndCurrentAnimation();
}

const Combo Attack::weakAttackNext() const
{
	return m_nextQCombo;
}

const Combo Attack::strengthAttackNext() const
{
	return m_nexySCombo;
}
