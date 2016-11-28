#include "../../../../header/actor/Player/specialSkill/SuperArmor.h"
#include "../../../../header/actor/Player/Status.h"
#include "../../../../header/actor/Player/Gauge.h"

SuperArmor::SuperArmor()
	:m_limitTimer(10),
	m_isSuperArmor(false)
{
}

SuperArmor::~SuperArmor()
{
}

void SuperArmor::initialize(Gauge * _gauge)
{
	if (!_gauge->down((float)RankGauge::SECOND))
	{
		return;
	}
	m_limitTimer.initialize();
	m_isSuperArmor = true;
}

void SuperArmor::update(float deltaTime)
{
	m_limitTimer.update(deltaTime);
	if (m_limitTimer.isEnd())
	{
		m_isSuperArmor = false;
	}
}

const bool SuperArmor::isEnd() const
{
	return m_limitTimer.isEnd();
}

const bool SuperArmor::isSuperArmor()
{
	return m_isSuperArmor;
}
