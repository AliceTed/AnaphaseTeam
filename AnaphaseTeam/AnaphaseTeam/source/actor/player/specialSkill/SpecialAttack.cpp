#include "../../../../header/actor/Player/specialSkill/SpecialAttack.h"
#include "../../../../header/actor/Player/Gauge.h"
#include "../../../../header/collision/CollisionGroup.h"
#include "../../../../header/collision/SpecialAttackCollision.h"
#include "../../../../header/actor/Player/Player.h"

SpecialAttack::SpecialAttack(Player* _player)
	:m_player(_player)
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
	m_player->specialAttack();
}

void SpecialAttack::update(float deltaTime)
{
}

const bool SpecialAttack::isEnd() const
{
	return m_player->isAnimationEnd();
}

void SpecialAttack::addColision(CollisionGroup * _group)
{
	Collision_Ptr actor = std::make_shared<SpecialAttackCollision>(m_player, this);
	_group->add(actor);
	m_player->specialAttack();
}
