/**
@file Spline.h
@brief ３次元スプライン曲線（注意：サイトまるコピ）
@author YuuhoAritomi
@date 2016/12/12
*/
#pragma once

class Spline
{
public:
	Spline(void);

	void init(double* _sp, int _num);

	double culc(double _t);

private:
	static const int MAX_SPLINE_SIZE = 100;

	int m_num;
	double m_a[MAX_SPLINE_SIZE + 1];
	double m_b[MAX_SPLINE_SIZE + 1];
	double m_c[MAX_SPLINE_SIZE + 1];
	double m_d[MAX_SPLINE_SIZE + 1];
};