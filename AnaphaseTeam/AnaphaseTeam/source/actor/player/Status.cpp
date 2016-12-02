#include "../../../header/actor/Player/Status.h"
#include"../../../header/actor/Player/Gauge.h"
#include "../../../header/math/Calculate.h"

Status::Status(float _hp)
	:def(3.0f),
	m_hp(_hp),
	m_defHp(_hp),
	m_AttackSpeed(def)
{
}

Status::~Status()
{
}

void Status::initialize()
{
	m_AttackSpeed = def;
	m_hp = m_defHp;
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

void Status::down(float _damage)
{
	m_hp -= _damage;
}

void Status::add()
{
	Math::Clamp clamp;
	m_hp += 5;
	m_hp = clamp(m_hp, 0.0f, 100.0f);
}
