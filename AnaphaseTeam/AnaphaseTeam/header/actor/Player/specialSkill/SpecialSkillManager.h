#pragma once
#include "../../../../header/actor/Player/specialSkill/Recovery.h"
#include "../../../../header/actor/Player/specialSkill/SuperArmor.h"
#include "../../../../header/actor/Player/specialSkill/SpecialAttack.h"

enum class SPECIALTYPE
{
	NONE,
	RECOVERY,
	SUPERARMOR,
	SPECIALATTACK
};

class Status;
class Gauge;

class SpecialSkillManager
{
public:
	SpecialSkillManager(Gauge& _gauge, Player* _player);
	~SpecialSkillManager();
	bool initialize(SPECIALTYPE _specialType);
	void update(float deltaTime);
	const bool isEnd(SPECIALTYPE _specialType) const;
	void recovery(Status& _status);
	bool isSuperArmor();
	void addAttackCollision(CollisionGroup* _group);
private:
	bool isGaugeCheck(float _gauge);
private:
	Recovery m_recovery;
	SuperArmor m_superArmor;
	SPECIALTYPE m_type;
	Gauge& m_gauge;
	SpecialAttack m_specialAttack;
};