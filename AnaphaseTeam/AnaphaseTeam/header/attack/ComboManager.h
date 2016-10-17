#pragma once
#include "AttackPattern.h"
#include "Attack.h"
#include "ComboManager.h"
#include "../device/Input.h"
#include <unordered_map>
#include "ECombo.h"
#include "ChargeAttack.h"
class AnimatorOne;

class IComboMadiator
{
public:
	virtual void  AttackEnd()=0;
};

class ComboManager:public IComboMadiator
{
public:
	ComboManager();
	~ComboManager();
	void initialize();
	void reset();
	void update(float deltaTime, Player* _player);
	void comboOrCharge(float deltaTime, Player * _player);
	const bool isEnd()const;	
private:	
	void create();
	void change(float deltaTime, Player* _player);
	void combo(float deltaTime,Player* _player);
	const Combo nextkey() const;
	void AttackEnd();
	const bool isCurrentEnd(Player* _player) const;
	const bool chargeEnd() const;
private:
	//コンボがスタートしたフレームかどうか
	bool m_isStart;
	bool m_isEnd;
	bool m_ChargeDecision;
	Combo m_currentKey;
	Combo m_nextKey;
	std::unordered_map<Combo, Attack> m_container;
	ChargeAttack m_chargeAttack;
};