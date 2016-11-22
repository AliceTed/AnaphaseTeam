#include "../../header/subAction/Avoid.h"
#include "../../header/actor/Player/Player.h"

const float Avoid::VELOCITY = 4.5f;
const float Avoid::TIME = 0.2f;
Avoid::Avoid(Player* _player)
	:m_player(_player),
	m_prebious(0,0,0),
	m_lerp(GSvector3(0, 0, 0)),
	m_justAvoidFlg(false),
	m_justTime(0.1f)
{
}

Avoid::~Avoid()
{
}

void Avoid::initialize()
{
	m_justAvoidFlg = false;
	m_justTime.initialize();
	GSvector3 dir = m_player->inputDirection();
	dir.normalize();
	m_lerp.start(dir,dir*VELOCITY, TIME);
	m_prebious = m_lerp.current();
}

void Avoid::update(float deltaTime)
{
	m_justTime.update(deltaTime);
	m_lerp.update(deltaTime);
	m_player->avoidAction(m_lerp.current() - m_prebious);
	m_prebious = m_lerp.current();
	//スリープでスローモーション仮実装
	if (m_justAvoidFlg)
	{
		Sleep(60);
	}
	
}

const bool Avoid::isEnd() const
{
	return m_lerp.isEnd();
}