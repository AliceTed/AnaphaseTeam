#pragma once
/**
* @file AttackState.h
* @brief PlayerpUXe[g 
* @author ΌφTη
* @date 2016/11/26
*/
#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"

enum class COMBOSTEP
{
	NON,
	START,
	END
};

class Player::AttackState:public ActorState<Player>
{
public:
 	Player::AttackState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//N[πμ¬·ι
	Player::AttackState* clone() const override;
	void input(float deltaTime);
private:
	Timer m_inputTimer;
	COMBOSTEP m_isCombo;
};