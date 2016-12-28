#include "../../header/spline/Spline.h"

const int Spline::MaxSplineSize = 100;

Spline::Spline(void) :
	m_num(0),
	m_a(MaxSplineSize + 1),
	m_b(MaxSplineSize + 1),
	m_c(MaxSplineSize + 1),
	m_d(MaxSplineSize + 1),
	m_isEnd(false)
{
	
}

Spline::~Spline()
{

}

void Spline::init(const std::vector<float>& _sp)
{
	float tmp;
	std::vector<float> w(MaxSplineSize + 1);
	int i;

	m_num = _sp.size() - 1;

	//３次多項目式の０次係数（a）を設定
	for (i = 0; i <= m_num; i++)
	{
		m_a[i] = _sp[i];
	}

	//３次多項目式の２次係数（a）を設定
	//連立方程式を解く
	//但し、一般開放でなくスプライン計算にチューニングした方法
	m_c[0] = m_c[m_num] = 0.0f;
	for (i = 1; i < m_num; i++)
	{
		m_c[i] = 3.0f * (m_a[i - 1] - 2.0f * m_a[i] + m_a[i + 1]);
	}
	//左下を消す
	w[0] = 0.0f;
	for (i = 1; i < m_num; i++)
	{
		tmp = 4.0f - w[i - 1];
		m_c[i] = (m_c[i] - m_c[i - 1]) / tmp;
		w[i] = 1.0f / tmp;
	}
	//右上を消す
	for (i = m_num - 1; i > 0; i--)
	{
		m_c[i] = m_c[i] - m_c[i + 1] * w[i];
	}

	//３次多項式の１次係数（b）と３次係数（b）を計算
	m_b[m_num] = m_d[m_num] = 0.0f;
	for (i = 0; i < m_num; i++)
	{
		m_d[i] = (m_c[i + 1] - m_c[i]) / 3.0f;
		m_b[i] = m_a[i + 1] - m_a[i] - m_c[i] - m_d[i];
	}
}

float Spline::culc(float _t, int _num)
{
	int j;
	float dt;

	m_isEnd = false;

	m_num = _num - 1;

	//j = static_cast<int>(floor(_t));			//小数点以下切り捨て 普段ならこっちを使う
	j = static_cast<int>(floor(m_num * _t));	//0 <= x <= 1の範囲で動くようにするためにこっちを使う
	if (j < 0)
	{
		j = 0;
		_t = 0;
	}
	else if (j >= m_num)
	{
		j = m_num - 1;	//丸め誤差を考慮

		//_t = static_cast<float>(m_num);		//普段ならこっち
		_t = 1;									//1の範囲を超えないように

		//終わったことを伝える
		m_isEnd = true;
	}

	//dt = _t - (float)j;						//普段ならこっちを使う
	dt = (m_num * _t) - (float)j;				//こっちも変えないと変な動きするから
	return m_a[j] + (m_b[j] + (m_c[j] + m_d[j] * dt) * dt) * dt;
}

bool Spline::isEnd(void)
{
	return m_isEnd;
}
