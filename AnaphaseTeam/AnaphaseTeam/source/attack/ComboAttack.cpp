#include "../../header/attack/ComboAttack.h"
#include "../../header/data/stream/AttackReader.h"
#include "../../header/actor/Player/Player.h"
ComboAttack::ComboAttack(Player* _player)
	:m_player(_player),
	m_container(),
	m_current(AttackStatus(), ANIMATION_ID::STAND, ATTACK_TYPE::End, ATTACK_TYPE::End),
	m_nextKey(ATTACK_TYPE::End),
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
		m_current = m_container.at(ATTACK_TYPE::S);
		m_current.initialize(m_player);
		return;
	}
	m_current = m_container.at(ATTACK_TYPE::Q);
	m_current.initialize(m_player);
}

void ComboAttack::update(float deltaTime)
{
	m_player->homing();
}

void ComboAttack::next(bool _isSlow)
{
	//“ü—Í‚ðŽó‚¯•t‚¯‚é‚©
	if (!m_player->isNextAttack(m_current))return;
	m_nextKey = m_current.next(_isSlow);
}

void ComboAttack::change()
{
	if (m_nextKey == ATTACK_TYPE::End)
	{
		m_isEnd = true;
		return;
	}
	m_current = m_container.at(m_nextKey);
	m_current.initialize(m_player);
	m_nextKey = ATTACK_TYPE::End;
}

const bool ComboAttack::isEnd() const
{
	return m_isEnd;
}
