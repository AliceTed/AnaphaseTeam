#include "../../header/attack/ComboAttack.h"
#include "../../header/data/stream/AttackReader.h"
#include "../../header/actor/Player/Player.h"
ComboAttack::ComboAttack(Player* _player)
	:m_player(_player),
	m_container(),
	m_current(AttackStatus(), ANIMATION_ID::STAND, ATTACK_TYPE::End, ATTACK_TYPE::End),
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
	//lerpでアニメーションが変わらないときがある
	m_current.motion(m_player);
}

const bool ComboAttack::next(bool _isSlow)
{
	ATTACK_TYPE next = m_current.next(_isSlow);
	if (next == ATTACK_TYPE::End)
	{
		return false;
	}
	m_current = m_container.at(next);
	m_current.initialize(m_player);
	return true;
}
const bool ComboAttack::isEnd() const
{
	return m_isEnd;
}
