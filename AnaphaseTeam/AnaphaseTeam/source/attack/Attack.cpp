#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
Attack::Attack(const AttackStatus & _status, ANIMATION_ID _animation, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_Shape(_shape)
{
}

Attack::~Attack()
{

}
void Attack::initialize()
{
}

void Attack::update(float deltaTime,Player * _player)
{
	motion(_player);
}

void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}

void Attack::changeMotion(AnimatorOne & _animator)
{
	_animator.changeAnimation(m_Animation, false, false, 2.0f);
}

const bool Attack::isEndMotion(const AnimatorOne & _animator) const
{
	return _animator.isEndCurrentAnimation();
}

bool Attack::isEndAttackTime(AnimatorOne & _animator)
{
	return _animator.isCombo(19);
}
