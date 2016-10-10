#pragma once

#include <gslib.h>
#include "../math/TimeLerpVector.h"
#include "../../header/convenient/Timer.h"
#include "../../header/collision/CollisionManager.h"

class Player;
class Transform;
class Avoid
{
public:
	Avoid(Player* _player);
	~Avoid();
	void initialize();
	void update(float deltaTime);
	const bool isEnd()const;
	void justAvoidCheck();
	bool isjustTimeEnd();
	void justAvoidRange(Group_Ptr _group, Transform & _transform);
	
private:
	Player* m_player;
	GSvector3 m_prebious;
	Math::TimeLerpVector<GSvector3> m_lerp;
	bool m_justAvoidFlg;
	Timer m_justTime;

	static const float VELOCITY;
	static const float TIME;
};