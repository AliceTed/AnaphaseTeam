#include "../../header/attack/ComboManager.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/animation/AnimatorOne.h"
ComboManager::ComboManager()
	:m_currentKey(Combo::End),
	m_nextKey(Combo::End),
	m_attackContainer(),
	m_isEnd(true),
	m_isStart(false),
	m_ChargeDecision(true),
	m_chargeAttack(AttackStatus(0.0f, 0.0f, GSvector3(0, 0, 0)), ANIMATION_ID::CHARGEATTACK, std::make_shared<Sphere>(GSvector3(0, 0, 0), 0))

{
}

ComboManager::~ComboManager()
{
}

void ComboManager::create()
{
	m_attackContainer.clear();
	m_comboContainer.clear();

	Shape_Ptr sphere = std::make_shared<Sphere>(GSvector3(0, 0, 0), 0);
	const unsigned int size = 5;
	Combo combo[size] =
	{
		Combo::First,
		Combo::Second,
		Combo::Third,
		Combo::Four,
		Combo::End
	};

	Combo combo2[size] =
	{
		Combo::First,
		Combo::Second,
		Combo::Third,
		Combo::End,
		Combo::End
	};

	ANIMATION_ID animation[size] =
	{
		ANIMATION_ID::ATTACK,
		ANIMATION_ID::ATTACK2,
		ANIMATION_ID::ATTACK3,
		ANIMATION_ID::ATTACK4,

	};

	ANIMATION_ID animation2[size] =
	{
		ANIMATION_ID::ATTACK,
		ANIMATION_ID::ATTACK4,
		ANIMATION_ID::ATTACK3,
		ANIMATION_ID::ATTACK2
	};

	for (unsigned int i = 0; i < size; i++)
	{
		AttackStatus status(0.0f, 0.0f, GSvector3(0, 0, 0));

		Attack attack(status, animation[i], combo[i + 1], sphere);
		m_attackContainer.insert(std::make_pair(combo[i], attack));
		
		Attack attack2(status, animation2[i], combo2[i + 1], sphere);
		m_attackContainer2.insert(std::make_pair(combo[i], attack2));
	}
	m_comboContainer.insert(std::make_pair(ComboPattern::Combo, m_attackContainer));
	m_comboContainer.insert(std::make_pair(ComboPattern::Combo2, m_attackContainer2));
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
	m_ChargeDecision = true;
	m_currentKey = Combo::First;
	m_nextKey = Combo::End;
	m_chargeAttack.initialize();
}

void ComboManager::comboOrCharge(float deltaTime, Player* _player)
{
	if (!m_chargeAttack.isStart())
		//m_attackContainer.at(m_currentKey).update(deltaTime, _player);
		m_comboContainer.at(ComboPattern::Combo).at(m_currentKey).update(deltaTime, _player);
	m_chargeAttack.update(deltaTime, _player);
}

void ComboManager::update(float deltaTime, Player* _player)
{
	
	comboOrCharge(deltaTime, _player);
	if (_player->isNextAttack(m_comboContainer.at(ComboPattern::Combo).at(m_currentKey))/*_player->isNextAttack(m_attackContainer.at(m_currentKey)) || _player->isNextAttack(m_attackContainer2.at(m_currentKey))*/)
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
	return  chargeEnd() && _player->isEndAttackMotion(m_attackContainer.at(m_currentKey));
}
const bool ComboManager::chargeEnd()const
{
	if (!m_ChargeDecision)return true;
	if (m_chargeAttack.isStart())return true;
	return m_chargeAttack.isChargeEnd();
}
void ComboManager::change(float deltaTime, Player * _player)
{
	if (!isCurrentEnd(_player))return;
	if (m_chargeAttack.isStart())
	{
		m_chargeAttack.endAttack(_player, this);
		return;
	}
	if (m_nextKey == Combo::End)
	{
		m_isEnd = true;
		return;
	}
	m_ChargeDecision = true;
	m_currentKey = m_nextKey;
	m_nextKey = Combo::End;
	m_chargeAttack.initialize();
}

void ComboManager::combo(float deltaTime, Player* _player)
{
	if (m_isStart)return;
	if (_player->isStrengthAttack())
	{
		m_nextKey = nextkey();
		change(deltaTime, _player);
		m_ChargeDecision = false;
		return;
	}
	if (m_ChargeDecision)
	{
		if (/*!m_chargeAttack.isStart()*/_player->isWeakAttack())
			m_chargeAttack.attackStart();
	}
}

const Combo ComboManager::nextkey() const
{
	//auto itr = m_attackContainer.find(m_currentKey);
	auto itr = m_comboContainer.at(ComboPattern::Combo).find(m_currentKey);
	//auto itr2 = m_attackContainer2.find(m_currentKey);
	if (itr == m_comboContainer.at(ComboPattern::Combo).end() /*m_attackContainer.end() || itr2 == m_attackContainer.end()*/)
	{
		return Combo::End;
	}
	return itr->second.next();
	//return itr2->second.next();
}

void ComboManager::AttackEnd()
{
	m_isEnd = true;
}