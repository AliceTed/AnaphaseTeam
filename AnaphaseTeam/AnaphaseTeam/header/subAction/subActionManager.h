#pragma once

#include "../subaction/JumpControl.h"
#include "Avoid.h"
enum class SubActionType
{
	NON,
	JUMP,
	AVOID
};

class subActionManager
{
public:
	subActionManager(Player* _player);
	~subActionManager();
	void initialize(SubActionType _type);
	void update(float deltaTime, SubActionType _type);
	const bool isEnd(SubActionType _type) const;

private:
	JumpControl m_jump;
	Avoid m_avoid;
	SubActionType m_current;
};