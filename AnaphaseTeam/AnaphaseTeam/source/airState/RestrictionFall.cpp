#include "../../header/airstate/RestrictionFall.h"
#include "../../header/airstate/GroundState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
#include "../../header/subAction/JumpControl.h"
const float RestrictionFall::Restriction = 0.0f;

RestrictionFall::RestrictionFall(JumpControl* _control, Player* _player)
	:m_isEnd(false),
	m_control(_control),
	m_player(_player)
{
}
RestrictionFall::~RestrictionFall()
{
}
void RestrictionFall::start()
{
	m_isEnd = false;
	m_player->startJump(m_control, Restriction);
}
void RestrictionFall::update(float deltaTime)
{
	m_player->jumpMotion(*m_control,ANIMATION_ID::LANDING);
	m_player->moving(deltaTime);
	m_control->jumping(deltaTime, m_player);
	change();
}

const bool RestrictionFall::isEnd() const
{
	return m_isEnd;
}

std::shared_ptr<IAirState> RestrictionFall::next() const
{
	return m_next;
}

void RestrictionFall::change()
{
	if (m_player->isGround())
	{
		m_isEnd = true;
		m_next = std::make_shared<GroundState>(m_control, m_player);
	}
}
