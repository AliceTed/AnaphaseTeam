#include "../../header/attack/ChargeAttack.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/attack/ComboManager.h"
ChargeAttack::ChargeAttack(const AttackStatus& _status, ANIMATION_ID _animation, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_nextCombo(Combo::End), m_Shape(_shape), m_isStart(false), m_isFirstFrame(false)
{

}
ChargeAttack::~ChargeAttack()
{

}
void ChargeAttack::initialize()
{
	m_isStart = false;
	m_chargeTime = 0;
	m_isKeyPushNow = true;
	m_isFirstFrame = false;
}
void ChargeAttack::update(float deltaTime, Player* _player)
{
	chargeStart(_player);

	if (m_isStart)
		motion(_player);
	m_isFirstFrame = false;

}
void ChargeAttack::endAttack(Player* _player, IComboMadiator* _manager)
{
	if (m_isFirstFrame == true)
		return;
	if (_player->isEndAttackMotion(*this))
	{
		m_isStart = false;
		_manager->AttackEnd();
	}
}

const bool ChargeAttack::isChargeEnd()const
{
	return !m_isKeyPushNow;
}
const bool ChargeAttack::isStart()const
{
	return m_isStart;
}

void ChargeAttack::attackStart(float _chargeTime)
{
	if (m_chargeTime <= _chargeTime)return;
	if (m_isKeyPushNow)return;
	m_isStart = true;
	m_isFirstFrame = true;
}

void ChargeAttack::motion(Player* _player)
{
	_player->attackmotion(*this);
}

void ChargeAttack::chargeStart(Player * _player)
{
	m_isKeyPushNow = _player->isChargeAttack();
	if (m_isKeyPushNow)
	{
		m_chargeTime++;
	}
}

void ChargeAttack::changeMotion(AnimatorOne& _animator)
{
	_animator.changeAnimation(m_Animation, false, false, 1.5f);
	//_animator.lerpBegin(m_Animation, true, false);
}
const bool ChargeAttack::isNextAttack(const AnimatorOne& _animator)const
{
	return false;
}
const bool ChargeAttack::isEndMotion(const AnimatorOne& _animator) const
{
	return _animator.isEndCurrentAnimation();
}