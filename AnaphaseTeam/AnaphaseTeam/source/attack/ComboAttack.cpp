#include "../../header/attack/ComboAttack.h"
#include "../../header/data/stream/AttackReader.h"
#include "../../header/actor/Player/Player.h"
ComboAttack::ComboAttack(Player* _player)
	:m_player(_player),
	m_container(),
	m_current(AttackParameter()),
	m_prev(AttackParameter()),
	m_isEnd(false)
{
}

void ComboAttack::initialize()
{
	m_container.clear();
	AttackReader reader;
	reader(&m_container, "combo");
}

void ComboAttack::start(bool _isSlow)
{
	m_isEnd = false;
	if (_isSlow)
	{
		m_current = m_container.at("SlowFirst");
		m_current.initialize(m_player);
		return;
	}
	
	m_current = m_container.at("QuickFirst");
	m_current.initialize(m_player);
}

void ComboAttack::update(float deltaTime)
{
	m_current.update(deltaTime, m_player);
}


bool ComboAttack::finish(Animator& _animator)
{
	return m_current.finish(_animator);
}

const bool ComboAttack::next(bool _isSlow)
{
	std::string next = m_current.next(_isSlow);
	if (next == "END")
	{
		m_isEnd = true;
		return false;
	}
	m_prev = m_current;
	m_current = m_container.at(next);

	m_current.initialize(m_player);
	return true;
}
bool ComboAttack::isAttack(Animator& _animator)
{
	return	m_current.getID() == _animator.getCurrent();
}

const bool ComboAttack::isEnd() const
{
	return m_isEnd;
}

const AttackStatus & ComboAttack::getStatus() const
{
	return m_current.getStatus();
}

const bool ComboAttack::isFinishAttack()
{
	std::string next = m_current.next(false);
	return next == "END";
}



