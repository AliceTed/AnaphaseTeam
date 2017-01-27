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
	@fn
	@brief コンストラクタ
	*/
	Shake();
	/**
	@fn
	@brief デストラクタ
	*/
	~Shake();
	/**
	@fn
	@brief 初期化
	@param _scale	ふり幅
	@param _time	振る時間（１秒＝６０フレーム）
	@param _center	原点
	*/
	void init(const GSvector3& _scale, const int _time, const GSvector3& _center);
	/**
	@fn
	@brief 実行
	*/
	GSvector3 run();
	/**
	@fn
	@brief 時間を初期化
	*/
	void resetTime(void);
private:
	std::unique_ptr<AnimationSpline> animSpline;	//スプラインアニメーション
};