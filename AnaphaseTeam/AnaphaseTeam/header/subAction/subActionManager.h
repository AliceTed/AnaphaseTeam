#pragma once
#include "../airstate/JumpControl.h"
#include "../subAction/TestChainMove.h"
class subActionManager
{
public:
	subActionManager();
	~subActionManager();
	void jumpInitialize();
	void action(Player* _player, float deltaTime);
	void groundHit();
	void jumpStart();
	void chainMoveStart();
	void restrictionFall();
private:
	TestChainMove m_chainMove;
	JumpControl m_jump;
};