#pragma once

#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Step.h"
class Player::HomingState :public ActorState<Player>
{
public:
	Player::HomingState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//ƒNƒ[ƒ“‚ğì¬‚·‚é
	Player::HomingState* clone() const override;
	void tracking();
private:
	Step m_step;

	float m_velocity;
};
