#pragma once
#include "header\actor\airstate\jumpControl.h"
#include "header\actor\TestChainMove.h"
class subActionManager
{
public:
	subActionManager();
	~subActionManager();

	void action(Player* _player, float deltaTime);
	void actionStart(Player* _player);

	void groundHit();
	const bool isfirstJump() const;

	jumpControl getjumpcontrol();
private:
	TestChainMove m_chainMove;
	jumpControl m_jump;
};