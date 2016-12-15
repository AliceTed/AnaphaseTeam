/**
@file Spline.h
@brief �X�v���C���Ȑ�
@author Yuuho Aritomi
@date 2016/12/15
*/

#include <vector>

class ASpline
{
public:
	//�R���X�g���N�^
	ASpline(void);

	//�f�X�g���N�^
	~ASpline();

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
	float culc(float _t);

protected:
	static const int MaxSplineSize;			//�z��̍ő�v�f�����Ɍ��߂Ă���

private:

	int m_num;								//�v�f����ێ����邽�߂̕ϐ�
	std::vector<float> m_a, m_b, m_c, m_d;	//���߂�悭�킩��Ȃ�
};