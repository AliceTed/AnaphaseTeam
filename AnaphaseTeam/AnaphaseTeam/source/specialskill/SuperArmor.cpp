#include "../../header/specialskill/SuperArmor.h"
#include "../../header/actor/Player/Gauge.h"
SuperArmor::SuperArmor()
	:m_limit(10.0f)
{
}

void SuperArmor::start()
{
	m_limit.initialize();
}

void SuperArmor::update(float deltaTime)
{
	m_limit.update(deltaTime);
}

const bool SuperArmor::isEnd() const
{
	return m_limit.isEnd();
}

const float SuperArmor::consumption()const
{
	return static_cast<float>(RankGauge::SECOND);
}
