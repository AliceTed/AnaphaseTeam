#pragma once
class Player;
class IEnemyAI
{public:
	virtual ~IEnemyAI() {}
	virtual void initialize() = 0;
	virtual void think(Player *_player) = 0;
};