#include "../../header/attack/ContinuationCombo.h"

ContinuationCombo::ContinuationCombo(const AttackStatus & _status, ANIMATION_ID _animation, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_Shape(_shape)
{
}

ContinuationCombo::~ContinuationCombo()
{
}

void ContinuationCombo::openAnAttack(Player* _player, TestActor * _other)
{
	m_status.giveDamage(_player,_other);
}
