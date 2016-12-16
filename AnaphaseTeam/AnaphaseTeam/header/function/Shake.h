/**
@file	Shake.h
@brief	シェイク処理（細かい調整は聞かないよ）
@author Yuuho Aritomi
@date	2016/12/16
*/
#pragma once

#include <gslib.h>
#include <vector>
#include <memory>

class AnimationSpline;
class SplineVec3;

class Shake
{
public:
	/**
	@brief コンストラクタ
	@param[_scale]	ふり幅
	@param[_time]	振る時間（１秒＝６０フレーム）
	*/
	Shake(const GSvector3& _scale, float _time);

	//デストラクタ
	~Shake();

	/**
	@brief 実行
	@param[_speed] 実行速度
	@return 結果
	*/
	GSvector3 run(float _speed);

	/**
	@brief 時間を初期化
	*/
	void resetTime(void);

private:
	std::vector<GSvector3> points;					//各点

	std::shared_ptr<SplineVec3> vecs;				//３次スプライン曲線

	std::unique_ptr<AnimationSpline> animSpline;	//スプラインアニメーション
};