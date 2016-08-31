#pragma once
#include "../actor/airstate/jumpControl.h"
#include "../subAction/TestChainMove.h"
class subActionManager
{
public:
	subActionManager();
	~subActionManager();
	void jumpInitialize();
	void action(Player* _player, float deltaTime);
	void actionStart(Player* _player);

	void groundHit();
	void jumpStart();

	void chainMoveStart();

	void restrictionFall();
private:
	TestChainMove m_chainMove;
	jumpControl m_jump;
};