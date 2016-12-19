/**
@file	CameraWorkNormalBattle
@brief	カメラ通常戦闘
@author	Yuuho Aritomi
@date	2016/12/19
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"

class CameraWorkNormalBattle : public CameraWorkEmpty
{
public:
	CameraWorkNormalBattle(Camera* _camera, bool* _isLockOn);

	//デストラクタ
	~CameraWorkNormalBattle() override;

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;

private:
	GSvector2 m_rotate;
	std::unique_ptr<CameraWorkEmpty> m_normal;
	std::unique_ptr<CameraWorkEmpty> m_lockon;
	bool* m_isLockOn;
};