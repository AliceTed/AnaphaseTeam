#include "../../header/attack/ComboManager.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"
ComboManager::ComboManager()
	:m_currentKey(Combo::End),
	m_nextKey(Combo::End),
	m_Pattern(),
	m_isEnd(false),
	m_isStart(false)
{
}

ComboManager::~ComboManager()
{
}

void ComboManager::create()
{
	m_Pattern.clear();

	Shape_Ptr sphere = std::make_shared<Sphere>(GSvector3(0, 0, 0), 0);
	const unsigned int size = 3;
	Combo combo[size] =
	{
		Combo::First,
		Combo::Second,
		Combo::Third
	};
	ANIMATION_ID animation[size] =
	{
		ANIMATION_ID::ATTACK,
		ANIMATION_ID::ATTACK2,
		ANIMATION_ID::ATTACK3
	};
	for (unsigned int i = 0; i < size; i++)
	{
		AttackStatus status(0.0f, 0.0f, GSvector3(0, 0, 0));
		Attack attack(status, animation[i], sphere);
		m_Pattern.insert(std::make_pair(combo[i], attack));
	}
}

void ComboManager::initialize()
{
	create();
	reset();
}

void ComboManager::reset()
{
	m_isEnd = false;
	m_isStart = true;
	m_currentKey = Combo::First;
	m_nextKey = Combo::End;
}

void ComboManager::update(float deltaTime, Player* _player)
{
	m_Pattern.at(m_currentKey).update(deltaTime,_player);

	change(deltaTime, _player);
	if (_player->isAttack())
	{
		combo(deltaTime);
	}
	m_isStart = false;
}

const bool ComboManager::isEnd() const
{
	return m_isEnd;
}

const bool ComboManager::isCurrentEnd(Player* _player) const
{
	return  _player->isEndAttackMotion(m_Pattern.at(m_currentKey));
}

void ComboManager::change(float deltaTime, Player * _player)
{
	if (!isCurrentEnd(_player))return;

	if (m_nextKey == Combo::End)
	{
		m_isEnd = true;
		return;
	}
	m_currentKey = m_nextKey;
	m_nextKey = Combo::End;
}

void ComboManager::combo(float deltaTime)
{
	if (m_isStart)return;
	m_nextKey = nextkey();
}

const Combo ComboManager::nextkey() const
{
	auto itr = m_Pattern.find(m_currentKey);
	itr++;
	if (itr == m_Pattern.end())
	{
		return Combo::End;
	}
	return itr->first;
}
