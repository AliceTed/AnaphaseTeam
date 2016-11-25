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