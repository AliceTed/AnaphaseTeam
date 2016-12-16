#include "..\..\header\attack\KnockBack.h"
#include "../../header/math/Calculate.h"
KnockBack::KnockBack(Transform & _transform)
	:m_transform(_transform),
	m_blowAway(),
	m_blowOff(0,0,0),
	m_timer(0)
{
}

void KnockBack::start(const GSvector3 & _blowOff)
{
	if (_blowOff.length() > 0.4f)m_blowAway = true;
	m_blowOff = _blowOff;
	m_timer.setEndTime(_blowOff.length());
	m_timer.initialize();
	//m_lerp.start(&m_current,_blowOff,GSvector3(0,0,0),_blowOff.length());
	
}

void KnockBack::update(float deltaTime)
{
	m_timer.update(deltaTime);
	Math::SinPower p;
	m_timer.accept([&](float _time, float _endtime) {m_current = p(m_blowOff, GSvector3(0, 0, 0), _time / _endtime, 0.5f); });
	m_transform.translate(m_current);
	if (m_timer.isEnd()) m_blowAway = false;
}
const bool KnockBack::isBlow()const
{
	return m_blowAway;
}
