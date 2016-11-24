#pragma once
#include "../../../../header/actor/Player/specialSkill/Recovery.h"
#include "../../../../header/actor/Player/specialSkill/SuperArmor.h"
#include "../../../../header/actor/Player/specialSkill/SpecialAttack.h"
#include "../../../../header/ui/SpAttackUI.h"

enum class SPECIALTYPE
{
	NONE,
	RECOVERY,
	SUPERARMOR,
	SPECIALATTACK
};

class Status;
class Gauge;
class Renderer;

class SpecialSkillManager
{
public:
	SpecialSkillManager(Gauge& _gauge, Player* _player);
	~SpecialSkillManager();
	bool initialize(SPECIALTYPE _specialType);
	void update(float deltaTime);
	//const bool isEnd(SPECIALTYPE _specialType) const;
	void endCheck();
	void recovery(Status& _status);
	bool isSuperArmor();
	void addAttackCollision(CollisionGroup* _group);

	void draw(const Renderer& _renderer);
private:
	bool isGaugeCheck(float _gauge);
	bool isRbstate();
private:
	Recovery m_recovery;
	SuperArmor m_superArmor;
	SPECIALTYPE m_type;
	Gauge& m_gauge;
	SpecialAttack m_specialAttack;
	SpAttackUI m_spAttackUI;
	
};