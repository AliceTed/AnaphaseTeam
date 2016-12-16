#include "../../header/specialskill/Recovery.h"
#include "../../header/actor/Player/Gauge.h"
#include "../../header/actor/Player/Player.h"
Recovery::Recovery(Player* _player)
	:m_limit(20.0f),
	m_player(_player)
{
}

void Recovery::start()
{
	m_limit.initialize();
	m_player->recovery();
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
