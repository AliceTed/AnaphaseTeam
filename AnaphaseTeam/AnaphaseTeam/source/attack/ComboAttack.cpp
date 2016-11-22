#include "../../header/attack/ComboAttack.h"
#include "../../header/actor/Player/Player.h"

ComboAttack::ComboAttack(const AttackStatus & _status, ANIMATION_ID _animation, Combo next, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_nextCombo(next), m_Shape(_shape)
{
}

ComboAttack::~ComboAttack()
{

}
void ComboAttack::initialize()
{
}

void ComboAttack::update(float deltaTime, Player * _player)
{
	motion(_player);
}

void ComboAttack::motion(Player * _player)
{
	_player->attackmotion(*this);
}

void ComboAttack::changeMotion(AnimatorOne & _animator)
{
	_animator.changeAnimation(m_Animation, false, false, 1.5f);
}

const bool ComboAttack::isNextAttack(const AnimatorOne & _animator) const
{
	float end = _animator.getCurrentAnimationEndTime();
	float current = _animator.getCurrentAnimationTime();
	float limit = 25.0f;
	return (end - limit) <= current;
}

const bool ComboAttack::isEndMotion(const AnimatorOne & _animator) const
{
	return _animator.isEndCurrentAnimation();
}
const Combo ComboAttack::next()const
{
	return m_nextCombo;
}