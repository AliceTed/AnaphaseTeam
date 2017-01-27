/**
@file
@brief ズームクラス
@author Yuuho Aritomi
@date 2017/01/27
*/
#pragma once

/**
@class
@brief ズームクラス
*/
class Zoom
{
public:
	/**
	@fn
	@brief デフォルトコンストラクタ
	*/
	Zoom();
	/**
	@fn
	@brief デストラクタ
	*/
	~Zoom();
	/**
	@fn 
	@brief 初期化
	@param _zoomズーム値
	*/
	void init(const float _zoom);
	/**
	@fn
	@brief 更新
	@param _zoom この参照値にズーム値を代入する
	*/
	void update(float* _zoom);
	/**
	@fn
	@brief ズームイン
	@param _speed ズームイン速度
	*/
	void zoomIN(const float _speed);
	/**
	@fn
	@brief ズームアウト
	@param _speed ズームアウト速度
	*/
	void zoomOut(const float _speed);
	/**
	@fn
	@brief ズームできる範囲を決定する
	@param _min ズームできる最小値
	@param _max ズームできる最大値
	*/
	void clamp(float _min, float _max);
private:
	float mZoomValue;
};