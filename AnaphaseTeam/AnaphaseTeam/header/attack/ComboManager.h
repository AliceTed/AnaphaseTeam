#pragma once
#include "AttackPattern.h"
#include "Attack.h"
#include "ComboManager.h"
#include <unordered_map>
enum class Combo
{
	First,
	Second,
	Third,
	Four,
	End,
	ChargeAttack
};

class AnimatorOne;
class ComboManager
{
public:
	ComboManager();
	~ComboManager();
	void initialize();
	void reset();
	void update(float deltaTime, Player* _player);
	const bool isEnd()const;	
private:	
	void create();
	void change(float deltaTime, Player* _player);
	void combo(float deltaTime);
	const Combo nextkey()const;
	const bool isCurrentEnd(Player* _player) const;
private:
	//コンボがスタートしたフレームかどうか
	bool m_isStart;
	bool m_isEnd;
	Combo m_currentKey;
	Combo m_nextKey;
	std::unordered_map<Combo, Attack> m_container;
};