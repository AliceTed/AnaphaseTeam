#include "../../header/attack/ContinuationCombo.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/collision/CollisionMediator.h"
ContinuationCombo::ContinuationCombo(const AttackStatus & _status, ANIMATION_ID _animation, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_Shape(_shape)
{
}

ContinuationCombo::~ContinuationCombo()
{
}

void ContinuationCombo::openAnAttack(Player* _player, TestActor * _other)
{
	m_status.giveDamage(_player,_other);
}

void ContinuationCombo::initialize()
{
}

void ContinuationCombo::update(float deltaTime,Player * _player)
{
	anime(_player);
}

void ContinuationCombo::anime(Player * _player)
{
	_player->animeID(m_Animation);
}
const bool ContinuationCombo::isEndAnimation(Player *_player) const
{
	return _player->isEndAnimation();
}