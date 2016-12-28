#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class Spline;

class SplineVec3
{
public:
	//�R���X�g���N�^
	SplineVec3(void);

	//�f�X�g���N�^
	~SplineVec3(void);

	/**
	@brief ������
	@param[_sp]
	*/
	void init(std::vector<GSvector3> _sp);

	/**
	@brief �X�v���C���Ȑ��̌v�Z
	@param[_t] 0 <= _t < = �v�f��
	@return ����
	*/
	GSvector3 culc(float _t);

	/**
	@return �A�j���[�V�������I���������H
	*/
	bool isEnd(void);

private:
	static const int MaxSplineSize;				//�z��̍ő�v�f�����Ɍ��߂Ă���

	int m_num;									//�v�f����ێ����邽�߂̕ϐ�

	std::unique_ptr<Spline> m_xs, m_ys, m_zs;	//�R���X�v���C��

	std::vector<float> m_x, m_y, m_z;			//�R��
};