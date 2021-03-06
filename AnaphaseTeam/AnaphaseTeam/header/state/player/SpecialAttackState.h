#pragma once
/**
* @file SpecialAttackState.h
* @brief PlayerpΑκUXe[g
* @author ΌφTη
* @date 2016/12/01
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "convenient/Timer.h"
class Player::SpecialAttackState:public ActorState<Player>
{
public:
	Player::SpecialAttackState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//N[πμ¬·ι
	Player::SpecialAttackState* clone() const override;

private:
	Timer m_spawnTimer;
};