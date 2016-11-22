#include "..\..\..\header\attack\AttackIncidence.h"

AttackIncidence::AttackIncidence(const Transform & _local)
{
}

void AttackIncidence::setWorldTransform(const Transform & _transform)
{
	m_world = _transform;
}

void AttackIncidence::synthesisWorldTransform(const Transform & _parent)
{
	m_world=m_world.parent_synthesis(_parent);
}

const GSvector3 AttackIncidence::point() const
{
	return m_local.parent_synthesis(m_world).m_translate;
}
