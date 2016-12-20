/**
@file AnimationSpline.h
@brief スプライン曲線アニメーション
@author Yuuho Aritomi
@date 2016/12/16
*/
#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class SplineVec3;

class AnimationSpline
{
public:

	/**
	@brief コンストラクタ
	*/
	AnimationSpline(void);

	//デストラクタ
	~AnimationSpline();

	/**
	@brief 初期化
	@param[_points] 各点
	*/
	void init(const std::vector<GSvector3>& _points);

	/**
	@brief 経過時間のリセット
	*/
	void resetTime(void);

	/**
	@brief 実行
	@param[_speed]実行速度
	@param[_center]原点
	@return 求めた位置　＋　原点
	*/
	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

	/**
	@return 終了したか？
	*/
	bool isEnd(void);

private:
	std::unique_ptr<SplineVec3> m_sVec3;

	float m_timer;
};