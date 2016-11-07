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

	//最初
	Attack Q(status, ANIMATION_ID::ATTACK, Combo::QQ, Combo::QS);
	Attack S(status, ANIMATION_ID::ATTACK3, Combo::SQ, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::Q, Q));
	m_attackPattern.insert(std::make_pair(Combo::S, S));

	//QQQQコンボ
	Attack QQ(status, ANIMATION_ID::ATTACK2, Combo::QQQ, Combo::End);
	Attack QQQ(status, ANIMATION_ID::ATTACK3, Combo::QQQQ, Combo::End);
	Attack QQQQ(status, ANIMATION_ID::ATTACK4, Combo::End, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::QQ, QQ));
	m_attackPattern.insert(std::make_pair(Combo::QQQ, QQQ));
	m_attackPattern.insert(std::make_pair(Combo::QQQQ, QQQQ));

	//QSQQコンボ
	Attack QS(status, ANIMATION_ID::ATTACK5, Combo::QSQ, Combo::End);
	Attack QSQ(status, ANIMATION_ID::ATTACK6, Combo::QSQQ, Combo::End);
	Attack QSQQ(status, ANIMATION_ID::FATTACK, Combo::End, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::QS, QS));
	m_attackPattern.insert(std::make_pair(Combo::QSQ, QSQ));
	m_attackPattern.insert(std::make_pair(Combo::QSQQ, QSQQ));

	//SQQコンボ
	Attack SQ(status, ANIMATION_ID::ATTACK, Combo::SQQ, Combo::End);
	Attack SQQ(status, ANIMATION_ID::ATTACK5, Combo::End, Combo::End);
	m_attackPattern.insert(std::make_pair(Combo::SQ, SQ));
	m_attackPattern.insert(std::make_pair(Combo::SQQ, SQQ));

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
