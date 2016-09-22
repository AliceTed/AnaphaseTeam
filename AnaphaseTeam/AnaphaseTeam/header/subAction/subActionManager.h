#pragma once

#include "../airstate/JumpControl.h"
#include "Avoid.h"
enum class SubActionType
{
	JUMP,
	AVOID
};

class subActionManager
{
public:
	subActionManager(Player* _player);
	~subActionManager();
	void initialize(SubActionType _type);
	void update(float deltaTime);
	const bool isEnd(SubActionType _type) const;
private:
	JumpControl m_jump;
	Avoid m_avoid;
	SubActionType m_current;
};