#pragma once

#include <gslib.h>

class CameraAction
{
public:
	/*********************
	@brief �f�X�g���N�^
	*********************/
	virtual ~CameraAction() { };

	/************
	@brief ���s
	************/
	virtual void run() = 0;
};

