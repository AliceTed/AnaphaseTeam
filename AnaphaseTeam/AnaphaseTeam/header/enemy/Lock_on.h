#pragma once
#include <gslib.h>
#include "../../header/actor/Enemy/BreakPoint.h"
#include "../math/TimeLerpVector.h"
class Player;
class CameraController;
class Lock_On
{
public:
	Lock_On();
	~Lock_On();

	void start(std::vector<BreakPoint>& _point);
	void update(float deltaTime);
	void lock_at(CameraController* _camera, Player* _actor);
private:
	int m_max;
	int m_target;
	int m_previous;
	Math::TimeLerpVector<GSvector3> m_lerp;
};
