#pragma once

class Gauge;
class CollisionGroup;
class Player;

class SpecialAttack
{
public:
	SpecialAttack(Player* _player);
	~SpecialAttack();
	void initialize(Gauge* _gauge);
	void update(float deltaTime);
	const bool isEnd() const;
public:
	void addColision(CollisionGroup* _group);
private:
	Player* m_player;
};