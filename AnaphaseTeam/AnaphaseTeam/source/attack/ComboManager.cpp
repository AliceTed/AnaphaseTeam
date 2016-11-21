#include "../../header/attack/ComboManager.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/animation/AnimatorOne.h"

ComboManager::ComboManager()
	:m_current(AttackStatus(0, 0, GSvector3()), ANIMATION_ID::ATTACK, Combo::End, Combo::End),
	m_next(Combo::End),
	m_attackPattern(),
	m_isEnd(false)
{
}

ComboManager::~ComboManager()
{
}

void ComboManager::create()
{
	m_comboReader.ComboCreate(&m_attack,&m_attackPattern);

}

void ComboManager::initialize()
{
	create();
	reset();

}

void ComboManager::reset()
{
	m_isEnd = false;
}

void ComboManager::Start(bool _attackChange)
{
	if (_attackChange)
	{
		m_current = m_attackPattern.at(Combo::Q);
	}

	if (!_attackChange)
	{
		m_current = m_attackPattern.at(Combo::S);
	}
}

void ComboManager::update(float deltaTime, Player* _player)
{

	if (_player->isNextAttack(m_current))
	{
		if (_player->isQuickAttack())
		{
			next(m_current.weakAttackNext());
		}

		if (_player->isSlowAttack())
		{
			next(m_current.strengthAttackNext());
		}
	}

	m_current.update(deltaTime, _player);

	if (isCurrentEnd(_player))
	{
		change();
		_player->homing();
	}
}


const bool ComboManager::isEnd() const
{
	return m_isEnd;
}

void ComboManager::next(Combo _next)
{
	if (_next == Combo::End)return;
	m_next = _next;
}

void ComboManager::change()
{
	if (m_next == Combo::End)
	{
		m_isEnd = true;
		return;
	}
	m_current = m_attackPattern.at(m_next);
	m_next = Combo::End;
}

const bool ComboManager::isCurrentEnd(Player* _player) const
{
	return _player->isEndAttackMotion(m_current);
}
