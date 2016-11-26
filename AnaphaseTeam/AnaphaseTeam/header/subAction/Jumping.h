#pragma once
class Player;
class Jumping
{
public:
	Jumping(Player* _player);
	~Jumping()=default;
	void start(float _power);
	void update(float deltaTime);
private:
	float m_power;
	Player* m_player;
	static const float MAX_POWER;
	static const float ACCELERATION;
};
