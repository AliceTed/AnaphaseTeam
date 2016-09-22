#pragma once

#include <gslib.h>
#include "../math/TimeLerpVector.h"
class Player;
class Avoid
{
public:
	Avoid(Player* _player);
	~Avoid();
	void initialize();
	void update(float deltaTime);
	const bool isEnd()const;
private:
	Player* m_player;
	GSvector3 m_prebious;
	Math::TimeLerpVector<GSvector3> m_lerp;

	static const float VELOCITY;
	static const float TIME;
};