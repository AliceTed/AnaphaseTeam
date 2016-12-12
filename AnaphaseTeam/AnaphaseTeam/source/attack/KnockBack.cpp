#include "..\..\header\attack\KnockBack.h"
KnockBack::KnockBack(Transform & _transform)
	:m_transform(_transform),
	m_lerp()
{
}

void KnockBack::start(const GSvector3 & _blowOff)
{
	m_lerp.start(&m_current,_blowOff,GSvector3(0,0,0),_blowOff.length());
}

void KnockBack::update(float deltaTime)
{
	m_lerp.update(deltaTime);
	m_transform.translate(m_current);
}

const bool KnockBack::isEnd() const
{
	return m_lerp.isEnd();
}
