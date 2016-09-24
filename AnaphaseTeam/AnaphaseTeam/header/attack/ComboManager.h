#pragma once
#include "AttackPattern.h"
#include "ContinuationCombo.h"
#include <unordered_map>
enum class Combo
{
	First,
	Second,
	Third,
	End
};

class ComboManager
{
public:
	ComboManager();
	~ComboManager();
	//Factor‚ğg‚¦‚ÎÁ‚¦‚éŠÖ”
	void create();
	void initilize();
	void update(float deltaTime, Player* _player);
	void combo(float deltaTime);
	const bool isEnd()const;
	const bool isCurrentEnd(const AnimatorOne * _animator) const;
private:	
	const Combo nextkey()const;
private:
	bool m_isEnd;
	Combo m_currentKey;
	std::unordered_map<Combo, ContinuationCombo> m_Pattern;
};