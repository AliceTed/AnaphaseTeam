#pragma once
#include "../airstate/IAirState.h"
#include<gslib.h>
#include <memory>
class Player;
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class jumpControl
{
public:
	jumpControl();
	~jumpControl();
	void initialize();
	void update(Player * _player, float deltaTime);
	const bool isGround()const;
	void groundHit();
	void jumping(Player* _player, float deltaTime);
	void start(const float _jumpStepPows);
private:
	void airActionChange(AirAction_Ptr _airAction);
private:
	float m_JumpPower;
	float m_Acceleration;
	enum class JUMPSTATE :unsigned int
	{
		Non,
		FristStep,
		SecondStep
	};
	JUMPSTATE m_State;
	static const float MaxJumpPower;
	AirAction_Ptr m_airAction;
};