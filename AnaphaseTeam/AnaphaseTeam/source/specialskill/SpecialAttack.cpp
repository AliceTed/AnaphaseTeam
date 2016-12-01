#include "../../header/specialskill/SpecialAttack.h"
#include "../../header/actor/Player/Gauge.h"
#include "../../header/actor/Player/Player.h"
SpecialAttack::SpecialAttack(Player* _player)
	:m_player(_player)
{
}

void SpecialAttack::start()
{
	m_player->changeState(ACTOR_STATE::SPECIALATTACK);
}

void SpecialAttack::update(float deltaTime)
{
}

const bool SpecialAttack::isEnd() const
{
	return true;
}

const float SpecialAttack::consumption()const
{
	return static_cast<float>(RankGauge::MAX);
}
