/****************************************************************
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "_CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/************************************************************
	@brief �R���X�g���N�^
	@param[_camera] �J����
	************************************************************/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);


	/************************************************************
	@brief �f�X�g���N�^
	************************************************************/
	~CameraWorkLockOn();

private:
	void draw_cameraWork(void) override;

	const GSvector3 centerPoint(const GSvector3& _p1, const GSvector3& _p2);

	void update_toEleDir(const GSvector3& _vec, float _distance);

private:
	GSvector2*							m_rotate;

	std::unique_ptr<CWParameterReader>	m_parameter;

	float								m_elevation;

	float								m_distance;
	float								m_distance_lockOn;

	float								m_followSpeed_position;
	float								m_followSpeed_target;
};