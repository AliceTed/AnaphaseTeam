#pragma once
#include "AttackPattern.h"
#include "Attack.h"
#include "ComboManager.h"
#include "ComboPattern.h"
#include "ECombo.h"
#include "ChargeAttack.h"

#include "../device/Input.h"

#include <unordered_map>

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
	//const ComboPattern currentCombo(std::unordered_map<ComboPattern, std::unordered_map<Combo, Attack>>& _map, const std::string& _key);
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
	ComboPattern m_currentCombo;
	std::unordered_map<Combo, Attack> m_attackContainer;
	std::unordered_map<Combo, Attack> m_attackContainer2;
	std::unordered_map<ComboPattern,std::unordered_map<Combo, Attack>> m_comboContainer;
	ChargeAttack m_chargeAttack;
};