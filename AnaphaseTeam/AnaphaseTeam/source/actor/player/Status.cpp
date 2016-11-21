#include "../../../header/actor/Player/Status.h"
#include"../../../header/actor/Player/Gauge.h"

Status::Status()
	:def(3.0f),
	m_hp(100),
	m_AttackSpeed(def)
{
}

Status::~Status()
{
}

void Status::initialize()
{
	m_AttackSpeed = def;
	m_hp = 100;
}

void Status::change(Gauge & _gauge)
{
	m_AttackSpeed = _gauge.scale(def);
}

float Status::attackSpeed()
{
	return m_AttackSpeed;
}

float Status::getHp()
{
	return m_hp;
}

void Status::down()
{
	m_hp -= 10;
}

void Status::add()
{
	m_hp += 10;
}
