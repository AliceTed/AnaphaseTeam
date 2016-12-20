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

	//�R�������ڎ��̂O���W���ia�j��ݒ�
	for (i = 0; i <= m_num; i++)
	{
		m_a[i] = _sp[i];
	}

	//�R�������ڎ��̂Q���W���ia�j��ݒ�
	//�A��������������
	//�A���A��ʊJ���łȂ��X�v���C���v�Z�Ƀ`���[�j���O�������@
	m_c[0] = m_c[m_num] = 0.0f;
	for (i = 1; i < m_num; i++)
	{
		m_c[i] = 3.0f * (m_a[i - 1] - 2.0f * m_a[i] + m_a[i + 1]);
	}
	//����������
	w[0] = 0.0f;
	for (i = 1; i < m_num; i++)
	{
		tmp = 4.0f - w[i - 1];
		m_c[i] = (m_c[i] - m_c[i - 1]) / tmp;
		w[i] = 1.0f / tmp;
	}
	//�E�������
	for (i = m_num - 1; i > 0; i--)
	{
		m_c[i] = m_c[i] - m_c[i + 1] * w[i];
	}

	//�R���������̂P���W���ib�j�ƂR���W���ib�j���v�Z
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

	//j = static_cast<int>(floor(_t));			//�����_�ȉ��؂�̂� ���i�Ȃ炱�������g��
	j = static_cast<int>(floor(m_num * _t));	//0 <= x <= 1�͈̔͂œ����悤�ɂ��邽�߂ɂ��������g��
	if (j < 0)
	{
		j = 0;
		_t = 0;
	}
	else if (j >= m_num)
	{
		j = m_num - 1;	//�ۂߌ덷���l��

		//_t = static_cast<float>(m_num);		//���i�Ȃ炱����
		_t = 1;									//1�͈̔͂𒴂��Ȃ��悤��

		//�I��������Ƃ�`����
		m_isEnd = true;
	}

	//dt = _t - (float)j;						//���i�Ȃ炱�������g��
	dt = (m_num * _t) - (float)j;				//���������ς��Ȃ��ƕςȓ������邩��
	return m_a[j] + (m_b[j] + (m_c[j] + m_d[j] * dt) * dt) * dt;
}

bool Spline::isEnd(void)
{
	return m_isEnd;
}
