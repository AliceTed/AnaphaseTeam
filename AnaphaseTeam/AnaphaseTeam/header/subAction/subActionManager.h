#pragma once

#include "../airstate/JumpControl.h"

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
	void initialize();
	void update(float deltaTime);
	const bool isEnd() const;
private:
	JumpControl m_jump;
};