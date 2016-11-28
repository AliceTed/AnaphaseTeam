#pragma once
#include "AttackPattern.h"
#include "Attack.h"
#include "ComboManager.h"
#include "ComboPattern.h"
#include "ECombo.h"
#include "ChargeAttack.h"
#include "ComboReader.h"

#include "../device/Input.h"

#include <unordered_map>
#include <vector>

class AnimatorOne;
class Attack;
class AttackStatus;

class IComboMadiator
{
public:
	virtual void  AttackEnd()=0;
};

class ComboManager//:public IComboMadiator
{
public:
	ComboManager();
	~ComboManager();
	void initialize();
	void start(bool attackChange,Player* _player);
	void reset();
	void update(float deltaTime, Player* _player);
	void nextAttack(float deltaTime, Player * _player);
	void nextIdentify(float deltaTime, Player* _player);
	const bool isEnd()const;
	float isPower();
	GSvector3 isBlow();
private:	
	void next(Combo _next);
	void change(Player* _player);
	void create();
	const bool isCurrentEnd(Player* _player) const;
private:
	bool m_attackFinished;
	bool m_isEnd;
	Attack m_current;
	Combo m_next;
	std::unordered_map<Combo, Attack> m_attackPattern;
	ComboReader m_comboReader;
	std::vector<AttackStatus> m_status;
	std::vector<Attack> m_attack;
};