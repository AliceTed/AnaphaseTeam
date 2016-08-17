#pragma once
/**
* @file TestJump.h
* @brief Jump‚ÌTest‚æ‚¤ƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/8/18
*/
class TestPlayer;
class TestJump
{
public:
	TestJump();
	~TestJump();
	void jumping(TestPlayer* _player,float deltaTime);
	void start();

	const bool isGround()const;
	void groundHit();
private:
	float m_JumpPower;
	float m_Acceleration;
	enum class JUMPSTATE:unsigned int
	{
		Non,
		FristStep,
		SecondStep
	};
	JUMPSTATE m_State;

	static const float FirstStepPow;
	static const float SecondStepPow;
	static const float MaxJumpPower;
};


