/**
@file AnimationSplineData.h
@brief スプラインアニメーション格納
@author Yuuho Aritomi
@date 2016/12/19
*/
#pragma once

#include <map>
#include <vector>
#include <memory>
#include <GSvector3.h>
#include <string>

#include "SPLINE_ANIMATION_ID.h"

class SplineVec3;
class AnimationSpline;

class AnimationSplineData
{
public:
	//コンストラクタ
	AnimationSplineData(void);

	//デストラクタ
	~AnimationSplineData();

	/**
	@brief 読み込み処理
	@param[_id]		ＩＤ
	@param[_points] 各点
	*/
	void add(SPLINE_ANIMATION_ID _id, const std::vector<GSvector3>& _points);
	/**
	@brief 読み込み処理
	@param[_id]			ＩＤ
	@param[_fileName]	ファイル名だけでOK
	*/
	void add(SPLINE_ANIMATION_ID _id, const std::string _fileName);

	/**
	*/
	void resetTime(void);

	/**
	@brief 指定したＩＤのスプラインアニメーションを実行
	@param[_id]		ID
	@param[_speed]	実行速度
	@param[_center] 原点
	@return 求めた位置　＋　原点
	*/
	AnimationSpline* get(SPLINE_ANIMATION_ID _id);

private:
	std::map<SPLINE_ANIMATION_ID, std::unique_ptr<AnimationSpline>> m_datas;
};