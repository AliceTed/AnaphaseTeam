#pragma once
#include "../actor/airstate/jumpControl.h"
#include "../actor/TestChainMove.h"
class subActionManager
{
public:
	subActionManager();
	~subActionManager();

	void action(Player* _player, float deltaTime);
	void actionStart(Player* _player);

	void groundHit();
	void jumpStart();

private:
	TestChainMove m_chainMove;
	jumpControl m_jump;
};