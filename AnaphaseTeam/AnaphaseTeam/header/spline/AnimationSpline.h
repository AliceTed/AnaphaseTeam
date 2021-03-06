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
	@param[_speed] スピード
	*/
	void init(const std::vector<GSvector3>& _points, float _speed, GSvector3 _center = { 0.0f, 0.0f, 0.0f });

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
	GSvector3 run();

	/**
	@return 終了したか？
	*/
	bool isEnd(void);

private:
	std::unique_ptr<SplineVec3> m_sVec3;

	GSvector3 m_center;
	float m_timer;
	float m_speed;
};