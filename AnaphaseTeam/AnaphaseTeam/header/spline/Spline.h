/**
@file Spline.h
@brief �X�v���C���Ȑ�
@author Yuuho Aritomi
@date 2016/12/15
*/

#include <vector>
#include <gslib.h>

class Spline
{
public:
	//�R���X�g���N�^
	Spline(void);

	//�f�X�g���N�^
	~Spline();

	/**
	@brief ������
	@param[_sp]
	*/
	void init(const std::vector<float>& _sp);

	/**
	@brief �X�v���C���Ȑ��̌v�Z
	@param[_t] 0 <= _t < = �v�f��
	@return ����
	*/
	float culc(float _t, int _num);

	/**
	@return �A�j���[�V�������I���������H
	*/
	bool isEnd(void);

private:
	static const int MaxSplineSize;			//�z��̍ő�v�f�����Ɍ��߂Ă���

	int m_num;								//�v�f����ێ����邽�߂̕ϐ�

	std::vector<float> m_a, m_b, m_c, m_d;	//���߂�悭�킩��Ȃ�

	bool m_isEnd;							//�A�j���[�V�������I���������H
};