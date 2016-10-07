#include "../../header/attack/ComboManager.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/animation/AnimatorOne.h"
ComboManager::ComboManager()
	:m_currentKey(Combo::End),
	m_nextKey(Combo::End),
	m_container(),
	m_isEnd(true),
	m_isStart(false),
	m_chargeKey(false),
	m_isKeyRelease(false),
	m_chargeTime(0.0f)

{
}

ComboManager::~ComboManager()
{
}

void ComboManager::create()
{
	m_container.clear();

	Shape_Ptr sphere = std::make_shared<Sphere>(GSvector3(0, 0, 0), 0);
	const unsigned int size = 5;
	Combo combo[size] =
	{
		Combo::First,
		Combo::Second,
		Combo::Third,
		Combo::Four,
		Combo::ChargeAttack
	};
	ANIMATION_ID animation[size] =
	{
		ANIMATION_ID::ATTACK,
		ANIMATION_ID::ATTACK2,
		ANIMATION_ID::ATTACK3,
		ANIMATION_ID::ATTACK4,
		ANIMATION_ID::CHARGEATTACK

	};
	for (unsigned int i = 0; i < size; i++)
	{
		AttackStatus status(0.0f, 0.0f, GSvector3(0, 0, 0));
		Attack attack(status, animation[i], sphere);
		m_container.insert(std::make_pair(combo[i], attack));
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
	m_chargeTime = 0;
	m_chargeKey = false;
	m_isKeyRelease = false;
	m_currentKey = Combo::First;
	m_nextKey = Combo::End;
}

void ComboManager::update(float deltaTime, Player* _player)
{
	if (m_isKeyRelease == false)
	{
		m_isKeyRelease = _player->isChargeAttack() == false;
	}


	m_container.at(m_currentKey).update(deltaTime, _player);

	if (_player->isChargeAttack())
	{
		m_chargeTime++;
	}
	if (_player->isNextAttack(m_container.at(m_currentKey)))
	{
		combo(deltaTime, _player);
	}
	change(deltaTime, _player);
	m_isStart = false;
}

const bool ComboManager::isEnd() const
{
	return m_isEnd;
}

const bool ComboManager::isCurrentEnd(Player* _player) const
{
	return  m_isKeyRelease&&_player->isEndAttackMotion(m_container.at(m_currentKey));
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
	m_isKeyRelease = false;
	m_chargeKey = false;
	m_chargeTime = 0;
}

void ComboManager::combo(float deltaTime, Player* _player)
{
	if (m_isStart)return;
	if (_player->isAttack())
	{
		m_nextKey = nextkey();
		m_chargeKey = true;
		return;
	}
	if (m_chargeKey == true||m_currentKey==Combo::ChargeAttack)return;
	if (m_isKeyRelease&& m_chargeTime >= 20.0f)
	{
		m_nextKey = Combo::ChargeAttack;
	}

}


const Combo ComboManager::nextkey() const
{
	auto itr = m_container.find(m_currentKey);
	itr++;
	if (itr == m_container.find(Combo::ChargeAttack))
	{
		return Combo::End;
	}
	if (itr == m_container.end())
	{
		return Combo::End;
	}
	return itr->first;
}
