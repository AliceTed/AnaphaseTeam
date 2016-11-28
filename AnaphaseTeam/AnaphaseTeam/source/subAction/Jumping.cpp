#include "../../header/subAction/Jumping.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
const float Jumping::MAX_POWER = 1.5f;
const float Jumping::ACCELERATION=0.05f;
Jumping::Jumping(Player * _player)
	:m_player(_player),
	m_power(0)
{
}

void Jumping::start(float _power)
{
	m_power = _power;
}

void Jumping::update(float deltaTime)
{
	m_player->jumping(m_power*deltaTime);
	Math::Clamp clamp;
	m_power = clamp(m_power - ACCELERATION, -MAX_POWER, MAX_POWER);
}
