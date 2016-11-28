#include "../../header/attack/AttackStatus.h"
#include "../../header/actor/Boss/Boss.h"
#include "../../header/actor/Player/Player.h"

#include "../../header/math/Calculate.h"
AttackStatus::AttackStatus(float _power, float _distanceDecay, const GSvector3 & _blowOff)
	:m_Power(_power), m_DistanceDecay(_distanceDecay), m_BlowOff(_blowOff)
{
}

AttackStatus::~AttackStatus()
{
}

void AttackStatus::giveDamage(Player* _player, Boss * _other)
{
	float distance = _player->distanceActor(*_other);
	Math::Clamp clamp;
	float pow = clamp(m_Power - distance, 0.0f, m_Power);

	//_other->beUnderAttack(pow,_player->vectorToFront(m_BlowOff));
}

float AttackStatus::isPower()
{
	return m_Power;
}