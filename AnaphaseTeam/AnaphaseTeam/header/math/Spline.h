/**
@file Spline.h
@brief ƒXƒvƒ‰ƒCƒ“‹Èü
@author Yuuho Aritomi
@date 2016/12/15
*/

#include <vector>

class Spline
{
public:
	Spline(void);

	~Spline();

	void init(const std::vector<float>& _sp, int _num);

	float culc(float _t);

private:
	static const int MaxSplineSize;

	int m_num;

	std::vector<float> m_a, m_b, m_c, m_d;
};