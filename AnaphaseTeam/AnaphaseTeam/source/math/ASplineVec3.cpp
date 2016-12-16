#include "../../header/math\ASplineVec3.h"
#include "../../header/math/ASpline.h"

const int ASplineVec3::MaxSplineSize = 100;

ASplineVec3::ASplineVec3(void) :
	m_num(0),
	m_xs(std::make_unique<ASpline>()),
	m_ys(std::make_unique<ASpline>()),
	m_zs(std::make_unique<ASpline>()),
	m_x(MaxSplineSize + 1),
	m_y(MaxSplineSize + 1),
	m_z(MaxSplineSize + 1)
{

}

ASplineVec3::~ASplineVec3(void)
{
}

void ASplineVec3::init(const std::vector<GSvector3>& _sp)
{
	m_num = _sp.size();

	for (int i = 0; i < m_num; i++)
	{
		m_x[i] = _sp[i].x;
		m_y[i] = _sp[i].y;
		m_z[i] = _sp[i].z;
	}

	m_xs->init(m_x);
	m_ys->init(m_y);
	m_zs->init(m_z);
}

GSvector3 ASplineVec3::culc(float _t)
{
	GSvector3 result = { m_xs->culc(_t), m_ys->culc(_t), m_zs->culc(_t) };
	return result;
}