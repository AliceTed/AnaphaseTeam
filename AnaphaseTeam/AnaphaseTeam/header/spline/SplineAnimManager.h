/**
@file	SplineManager.h
@brief	スプライン管理者
@author Yuuho Aritomi
@date	2016/12/19
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "SPLINE_ANIMATION_ID.h"

class AnimationSplineData;

class SplineAnimManager
{
public:
	//コンストラクタ
	SplineAnimManager(void);

	//デストラクタ
	~SplineAnimManager();

	/**
	@brief 読み込み処理
	*/
	void load(void);

	/**
	@brief アニメーションＩＤを切り替える
	@param[_id] アニメーションＩＤ*/
	void changeID(SPLINE_ANIMATION_ID _id);

	/**
	@brief 実行
	@param[_speed]	速度
	@param[_center]	原点
	*/
	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

	/**
	@return 終了したか？
	*/
	bool isEnd(void);

private:
	SPLINE_ANIMATION_ID m_currentID;

	std::unique_ptr<AnimationSplineData> m_datas;
};