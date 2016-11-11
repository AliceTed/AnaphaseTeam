#pragma once
#include"../../../../header/actor/Player/specialSkill/Recovery.h"

enum class SPECIALTYPE
{
	NONE,
	RECOVERY
};

class Status;

class SpecialSkillManager
{
public:
	SpecialSkillManager();
	~SpecialSkillManager();
	void initialize(SPECIALTYPE _specialType);
	void update(float deltaTime);
	const bool isEnd(SPECIALTYPE _specialType) const;
	void recovery(Status& _status);
private:
	Recovery m_recovery;
	SPECIALTYPE m_type;
};