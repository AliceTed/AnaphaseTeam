#include "actor/Player/Status.h"
#include"actor/Player/Gauge.h"
#include "math/Calculate.h"

Status::Status()
	:
	def(3.0f),
	m_hp(0),
	m_maxHp(0),
	m_AttackSpeed(def)
{
}

Status::~Status()
{
}

void Status::initialize()
{
	m_AttackSpeed = def;
	m_hp = m_maxHp;
}

void Status::change(Gauge & _gauge)
{
	m_AttackSpeed = _gauge.scale(def);
}

float Status::attackSpeed() const
{
	return m_AttackSpeed;
}

float Status::getHp()
{
	return m_hp;
}

const float Status::getMaxHp() const
{
	return m_maxHp;
}

void Status::down(float _damage)
{
	add(-_damage);
}

void Status::add(float _amount)
{
	Math::Clamp clamp;
	m_hp += _amount;
	m_hp = clamp(m_hp, 0.0f, 100.0f);
}
