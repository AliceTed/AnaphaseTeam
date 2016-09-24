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
	//Factorを使えば消える関数
	void create();
	void initialize();
	void update(float deltaTime, Player* _player);
	
	const bool isEnd()const;
	const bool isCurrentEnd(Player* _player) const;
private:	
	void change(float deltaTime, Player* _player);
	void combo(float deltaTime);
	const Combo nextkey()const;
private:
	bool isStart;//コンボがスタートしたフレームかどうか
	bool m_isEnd;
	Combo m_currentKey;
	Combo m_nextKey;
	std::unordered_map<Combo, ContinuationCombo> m_Pattern;
};