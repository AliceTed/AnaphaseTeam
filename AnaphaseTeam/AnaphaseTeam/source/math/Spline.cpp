#include "../../header/math/Spline.h"

Spline::Spline(void) :
	m_num(0)
{

}

void Spline::init(double * _sp, int _num)
{
	double tmp, w[MAX_SPLINE_SIZE + 1];
	int i;
	
	m_num = _num - 1;

	//�R�����������̂O���W��(a)��ݒ�
}

double Spline::culc(double _t)
{
	return 0.0;
}
