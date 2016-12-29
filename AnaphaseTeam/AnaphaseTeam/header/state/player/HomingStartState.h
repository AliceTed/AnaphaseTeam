#pragma once

#include "../../actor/Player/Player.h"
#include "../ActorState.h"
#include "../../subAction/Step.h"
class Player::HomingStartState :public ActorState<Player>
{
public:
	Player::HomingStartState(Player* _player);
private:
	void start()override;
	void action(float deltaTime)override;
	//�N���[�����쐬����
	Player::HomingStartState* clone() const override;
};