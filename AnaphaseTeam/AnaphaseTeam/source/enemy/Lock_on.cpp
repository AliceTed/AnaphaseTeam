#include "../../header/enemy/Lock_on.h"
#include "../../header/camera/CameraController.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/math/Calculate.h"
Lock_On::Lock_On()
	:m_max(0),
	m_target(0),
	m_previous(0),
	m_lerp(GSvector3(0,0,0))
{
}

Lock_On::~Lock_On()
{
}

void Lock_On::start(std::vector<BreakPoint>& _point)
{
	Math::Wrap warp;
	m_previous = m_target;
	int size = _point.size();
	m_target = warp(m_target + 1, 0, size);
	_point.at(m_previous).lerp(m_lerp,_point.at(m_target));
}

void Lock_On::update(float deltaTime)
{
	m_lerp.update(deltaTime);
}

void Lock_On::lock_at(CameraController * _camera, Player * _actor)
{
	GSvector3 target = m_lerp.current();
	_actor->look_at(_camera,&target);
}
