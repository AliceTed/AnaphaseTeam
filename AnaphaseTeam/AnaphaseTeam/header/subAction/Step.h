#pragma once

#include <gslib.h>
#include "../math/TimeLerpVector.h"
class Player;
struct Transform;
class Step
{
public:
	Step(Player* _player);
	~Step()=default;
	void start(const GSvector3& _direction, float _velocity);
	void update(float deltaTime);
	const bool isEnd()const;	
private:
	Player* m_player;
	GSvector3 m_prebious;
	Math::TimeLerpVector<GSvector3> m_lerp;

	static const float TIME;
};