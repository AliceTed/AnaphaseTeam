#include "../../../header/actor/Player/Status.h"
#include"../../../header/actor/Player/Gauge.h"

Status::Status()
	:def(1.0f),
	m_AttackSpeed(def)
{
}

Status::~Status()
{
}

void Status::initialize()
{
	m_AttackSpeed = def;
}

void Status::change(Gauge & _gauge)
{
	m_AttackSpeed = _gauge.scale(def);
}

float Status::attackSpeed()
{
	return m_AttackSpeed;
}
