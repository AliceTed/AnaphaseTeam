/**
@file AnimationSpline.h
@brief スプライン曲線アニメーション
@author Yuuho Aritomi
@date 2016/12/16
*/
#pragma once

#include <gslib.h>
class SplineVec3;

class AnimationSpline
{
public:
	/**
	@brief コンストラクタ
	@param[_sVec3]
	*/
	AnimationSpline(SplineVec3* _sVec3);

	//デストラクタ
	~AnimationSpline();

	/**
	@brief 経過時間のリセット
	*/
	void resetTime(void);

	/**
	@brief 実行
	@param[_speed]実行速度
	@return 速度*/
	GSvector3 run(float _speed);

private:
	SplineVec3* m_sVec3;

	float m_timer;
};