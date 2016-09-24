#include "../../header/attack/ComboManager.h"
#include "../../header/shape/Sphere.h"
ComboManager::ComboManager()
	:m_currentKey(Combo::End),
	m_Pattern(),
	m_isEnd(false)
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
	ANIMATION_ID animation[size]=
	{
		ANIMATION_ID::ATTACK,
		ANIMATION_ID::ATTACK2,
		ANIMATION_ID::ATTACK3
	};
	for (unsigned int i = 0; i < size; i++)
	{
		AttackStatus status(0.0f, 0.0f, GSvector3(0, 0, 0));
		ContinuationCombo attack(status, animation[i], sphere);
		m_Pattern.insert(std::make_pair(combo[i], attack));
	}
}

void ComboManager::initilize()
{
	m_isEnd=false;
	m_currentKey= Combo::First;
}

void ComboManager::update(float deltaTime,Player* _player)
{
	m_Pattern.at(m_currentKey).anime(_player);
}

const bool ComboManager::isEnd() const
{
	return m_isEnd;
}

const bool ComboManager::isCurrentEnd(const AnimatorOne * _animator) const
{
	return m_Pattern.at(m_currentKey).isEndAnimation(_animator);;
}

void ComboManager::combo(float deltaTime)
{
	Combo next = nextkey();
	if (next == Combo::End)
	{
		m_isEnd = true;
		return;
	}
	m_currentKey = next;
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
