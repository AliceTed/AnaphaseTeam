#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
Attack::Attack(const AttackStatus & _status, ANIMATION_ID _animation, ATTACK_TYPE _nextQuick, ATTACK_TYPE _nextSlow)
	:m_status(_status), m_Animation(_animation), m_nextQuick(_nextQuick),m_nextSlow(_nextSlow)
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


void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}
void Attack::changeMotion(AnimatorOne & _animator, float _speed)
{
	_animator.changeAnimation(static_cast<GSuint>(m_Animation),true, false, false,3.0f, _speed);
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

const ATTACK_TYPE Attack::next(bool _isSlow) const
{
	return _isSlow?m_nextSlow:m_nextQuick;
}
