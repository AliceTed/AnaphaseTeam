#include "../../header/spline/SplineVec3.h"
#include "../../header/spline/Spline.h"

const int SplineVec3::MaxSplineSize = 100;

SplineVec3::SplineVec3(void) :
	m_num(0),
	m_xs(std::make_unique<Spline>()),
	m_ys(std::make_unique<Spline>()),
	m_zs(std::make_unique<Spline>()),
	m_x(MaxSplineSize + 1),
	m_y(MaxSplineSize + 1),
	m_z(MaxSplineSize + 1)
{

}

SplineVec3::~SplineVec3(void)
{

}

void SplineVec3::init(std::vector<GSvector3> _sp)
{
	int i;

	for (i = 0; i < m_num; i++)
	{
		m_x[i] = 0;
		m_y[i] = 0;
		m_z[i] = 0;
	}

	m_num = _sp.size();

	for (i = 0; i < m_num; i++)
	{
		m_x[i] = _sp[i].x;
		m_y[i] = _sp[i].y;
		m_z[i] = _sp[i].z;
	}

	m_xs->init(m_x);
	m_ys->init(m_y);
	m_zs->init(m_z);
}

GSvector3 SplineVec3::culc(float _t)
{
	GSvector3 result = { m_xs->culc(_t, m_num), m_ys->culc(_t, m_num), m_zs->culc(_t, m_num) };

	return result;
}

bool SplineVec3::isEnd(void)
{
	return m_xs->isEnd();
}
