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
	void add(std::string _id, const std::vector<GSvector3>& _points);
	/**
	@brief 読み込み処理
	@param[_id]			ＩＤ
	@param[_fileName]	ファイル名だけでOK
	*/
	void add(std::string _id, const std::string _fileName);

	/**
	@brief 指定したＩＤのスプラインアニメーションを実行
	@param[_id]		ID
	@param[_speed]	実行速度
	@param[_center] 原点
	@return 求めた位置　＋　原点
	*/
	AnimationSpline* get(std::string _id);

private:
	using AnimationSplineMap = std::map<std::string, std::unique_ptr<AnimationSpline>>;

	AnimationSplineMap m_datas;
};