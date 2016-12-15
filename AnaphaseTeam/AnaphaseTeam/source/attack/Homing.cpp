#include "..\..\header\attack\Homing.h"
#include "../../header/actor/Enemy/IEnemy.h"
#include "../../header/math/Calculate.h"
#include "../../header/actor/Player/Gauge.h"
#include "../../header/actor/Player/Player.h"

Homing::Homing()
	:m_isStart(false),
	m_position(0,0,0),
	m_target(0,0,0)
{
}

Homing::~Homing()
{
}

void Homing::start(Player * _player, IEnemy * _enemy, Transform& _transform, Gauge& _gauge,GSvector3 _distance, bool _islockon)
{
	IEnemy* target = _enemy;
	if (target == nullptr) return;
	if (_player->distanceActor(*target) >= 3.0f)
	{
		m_isStart = false;
		return;
	}
	_transform.m_rotate = _player->targetDirection(*target);
	float velocity = _player->distanceActor(*target) / 5.0f;
	Math::Clamp clamp;
	velocity = clamp(_gauge.scale(velocity), 0.0f, _player->distanceActor(*target) - 1.0f);
	_distance = _transform.m_translate + (_transform.front() * velocity);
	m_isStart = true;
	m_target = _distance;
}

void Homing::update(float deltatime,GSvector3* _position)
{
	if (m_isStart)
		gsVector3Lerp(_position,
			_position, &m_target, deltatime * 0.1f);
}
