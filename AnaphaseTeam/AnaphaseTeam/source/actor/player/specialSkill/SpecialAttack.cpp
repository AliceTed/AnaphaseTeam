#include "../../../../header/actor/Player/specialSkill/SpecialAttack.h"
#include "../../../../header/actor/Player/Gauge.h"

SpecialAttack::SpecialAttack()
{
}

SpecialAttack::~SpecialAttack()
{
}

void SpecialAttack::initialize(Gauge* _gauge)
{
	if (!_gauge->down((float)RankGauge::MAX))
	{
		return;
	}
}

void SpecialAttack::update(float deltaTime)
{
}

const bool SpecialAttack::isEnd() const
{
	return false;
}
