#include "../../../../header/actor/Player/specialSkill/Recovery.h"
#include "../../../../header/actor/Player/Status.h"
#include "../../../../header/actor/Player/Gauge.h"

Recovery::Recovery() :
	m_limitTimer(20)
{
}

Recovery::~Recovery()
{
}

void Recovery::initialize()
{
	if (m_gauge->down(150))return;
	m_limitTimer.initialize();
}

void Recovery::update(float deltaTime)
{
	m_limitTimer.update(deltaTime);
}

void Recovery::add(Status & _status)
{
	if (!m_limitTimer.isEnd()) _status.add();
}

const bool Recovery::isEnd() const
{
	return m_limitTimer.isEnd();
}
