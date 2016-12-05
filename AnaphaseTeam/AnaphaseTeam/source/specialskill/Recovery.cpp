#include "../../header/specialskill/Recovery.h"
#include "../../header/actor/Player/Gauge.h"
Recovery::Recovery()
	:m_limit(20.0f)
{
}

void Recovery::start()
{
	m_limit.initialize();
}

void Recovery::update(float deltaTime)
{
	m_limit.update(deltaTime);
}

const bool Recovery::isEnd() const
{
	return m_limit.isEnd();
}

const float Recovery::consumption()const
{
	return static_cast<float>(RankGauge::FIRST);
}
