#include "../../header/subAction/Step.h"
#include "../../header/actor/Player/Player.h"

const float Step::VELOCITY = 4.5f;
const float Step::TIME = 0.2f;
Step::Step(Player* _player)
	:m_player(_player),
	m_prebious(0,0,0),
	m_lerp(GSvector3(0, 0, 0))
{
}

void Step::start(const GSvector3 & _direction)
{
	m_lerp.start(_direction, _direction*VELOCITY, TIME);

	m_prebious = m_lerp.current();
}

void Step::update(float deltaTime)
{
	m_lerp.update(deltaTime);
	m_player->avoidAction(m_lerp.current() - m_prebious);
	m_prebious = m_lerp.current();	
}

const bool Step::isEnd() const
{
	return m_lerp.isEnd();
}