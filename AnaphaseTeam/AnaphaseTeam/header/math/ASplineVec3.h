#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class ASpline;

class ASplineVec3
{
public:
	//�R���X�g���N�^
	ASplineVec3(void);

	//�f�X�g���N�^
	~ASplineVec3(void);

	/**
	@brief ������
	@param[_sp]
	*/
	void init(const std::vector<GSvector3>& _sp);

	/**
	@brief �X�v���C���Ȑ��̌v�Z
	@param[_t] 0 <= _t < = �v�f��
	@return ����
	*/
	GSvector3 culc(float _t);

private:
	static const int MaxSplineSize;				//�z��̍ő�v�f�����Ɍ��߂Ă���

	int m_num;									//�v�f����ێ����邽�߂̕ϐ�

	std::unique_ptr<ASpline> m_xs, m_ys, m_zs;	//�R���X�v���C��

	std::vector<float> m_x, m_y, m_z;			//�R��
};