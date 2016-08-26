#pragma once
/**
* @file TestJump.h
* @brief Jump��Test�悤�N���X
* @author �����T��
* @date 2016/8/18
*/
class Player;
class TestJump
{
public:
	TestJump();
	~TestJump();
	void jumping(Player* _player,float deltaTime);
	void start(const float _jumpStepPows);

	const bool isGround()const;
	void groundHit();
private:
	float m_JumpPower;
	float m_Acceleration;
	/*enum class JUMPSTATE:unsigned int
	{
		Non,
		FristStep,
		SecondStep
	};
	JUMPSTATE m_State;*/

	static const float FirstStepPow;
	static const float SecondStepPow;
	static const float MaxJumpPower;
};


