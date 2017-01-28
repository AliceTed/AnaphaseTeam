/**
@file
@brief	パースペクティブ
@author Yuuho Aritomi
@date	2017/01/27
*/
#pragma once

#include <gslib.h>
#include <memory>

class IRenderer;
class Zoom;

/**
@file
@brief パースペクティブ
*/
class Perspective
{
public:
	/**
	@fn
	@brief デフォルトコンストラクタ
	*/
	Perspective();
	/**
	@fn
	@brief デストラクタ
	*/
	~Perspective();
	/**
	@fn
	@brief 初期化
	*/
	void init(const GSvector4& _perspective);
	/**
	@fn
	@brief 更新
	*/
	void update();
	/**
	@fn
	@brief 更新（レンダラー）
	@param _renderer レンダラー
	*/
	void update(IRenderer* _renderer);
	/**
	@fn
	@brief パースペクティブ値を返す
	@return パースペクティブ値
	*/
	GSvector4 perspective();
	/**
	@fn
	@brief ズーム機能を渡す
	@return ズーム機能
	*/
	Zoom* zoom();
	/**
	@fn
	@brief 後で消す
	*/
	float near();
	/**
	@fn
	@brief 後で消す
	*/
	GSmatrix4 matProjective();
private:
	//視野角と遠近情報
	GSvector4 mPerspective;
	//シェーダー用投射変換行列
	GSmatrix4 mMatProjection;
	//ズーム機能
	std::unique_ptr<Zoom> mZoom;
};