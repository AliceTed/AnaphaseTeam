#pragma once

#include <gslib.h>

class CameraAction
{
public:
	/*********************
	@brief デストラクタ
	*********************/
	virtual ~CameraAction() { };

	/************
	@brief 実行
	************/
	virtual void run() = 0;
};

