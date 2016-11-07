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
	m_attackPattern.clear();

	AttackStatus status(0.0f, 0.0f, GSvector3(0, 0, 0));

	//
	Attack QFirst(status, ANIMATION_ID::ATTACK, Combo::QSecond, Combo::QSSecond);
	Attack SFirst(status, ANIMATION_ID::FATTACK, Combo::End, Combo::SSecond);
	m_attackPattern.insert(std::make_pair(Combo::QFirst, QFirst));
	m_attackPattern.insert(std::make_pair(Combo::SFirst, SFirst));

	//
	Attack QSecond(status, ANIMATION_ID::ATTACK2, Combo::QThird, Combo::End);
	Attack SSecond(status, ANIMATION_ID::ATTACK5, Combo::End, Combo::SThird);
	Attack QSSecond(status, ANIMATION_ID::ATTACK5, Combo::SQThird, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::QSecond, QSecond));
	m_attackPattern.insert(std::make_pair(Combo::SSecond, SSecond));
	m_attackPattern.insert(std::make_pair(Combo::QSSecond, QSSecond));

	//
	Attack QThird(status, ANIMATION_ID::ATTACK3, Combo::QFour, Combo::End);
	Attack SThird(status, ANIMATION_ID::ATTACK6, Combo::End, Combo::End);
	Attack SQThird(status, ANIMATION_ID::ATTACK6, Combo::SQFour, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::QThird, QThird));
	m_attackPattern.insert(std::make_pair(Combo::SThird, SThird));
	m_attackPattern.insert(std::make_pair(Combo::SQThird, SQThird));

	//
	Attack QFour(status, ANIMATION_ID::ATTACK4, Combo::End, Combo::End);
	Attack SQFour(status, ANIMATION_ID::FATTACK, Combo::End, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::QFour, QFour));
	m_attackPattern.insert(std::make_pair(Combo::SQFour, SQFour));



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
		m_current = m_attackPattern.at(Combo::QFirst);
	}

	if (!_attackChange)
	{
		m_current = m_attackPattern.at(Combo::SFirst);
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
	}
}


const bool ComboManager::isEnd() const
{
	return m_isEnd;
}

void ComboManager::next(Combo _next)
{
	if (_next == Combo::End)return;
	m_next =_next;
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





