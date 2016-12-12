#include "..\..\header\attack\KnockBack.h"
KnockBack::KnockBack(Transform & _transform)
	:m_transform(_transform),
	m_lerp(), m_blowAway()
{
}

void KnockBack::start(const GSvector3 & _blowOff)
{
	if (_blowOff.length() > 0.4f)m_blowAway = true;
	m_lerp.start(&m_current,_blowOff,GSvector3(0,0,0),_blowOff.length());
}

void KnockBack::update(float deltaTime)
{
	m_lerp.update(deltaTime);
	m_transform.translate(m_current);
	if (m_lerp.isEnd())m_blowAway = false;
}
const bool KnockBack::isBlow()const
{
	return m_blowAway;
}

const bool KnockBack::isEnd() const
{
	return m_lerp.isEnd();
}
