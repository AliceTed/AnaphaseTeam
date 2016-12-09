/**
@file CameraTarget.h
@brief カメラのターゲット
*/
#pragma once

#include <gslib.h>

class CameraTarget
{
public:
	/**
	@brief コンストラクタ
	*/
	CameraTarget(void);

	/**
	@brief デストラクタ
	*/
	~CameraTarget();

	/**
	@brief 注視点変更
	@param[_target] ターゲット
	*/
	void lookAt(const GSvector3& _target);

	/**
	@return ターゲット
	*/
	const GSvector3& _target(void) const;

private:
	GSvector3 m_target;	//ターゲット位置
};