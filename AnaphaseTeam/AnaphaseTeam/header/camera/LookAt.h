/**
@file
@brief	カメラの位置情報用の変数をまとめてるだけ
@author Yuuho Aritomi
@date	2016/12/08
*/
#pragma once

#include <gslib.h>
#include "transform/Transform.h"

class IRenderer;
class Map;

struct LookAt
{
public:
	/**
	@fn
	@brief デフォルトコンストラクタ
	*/
	LookAt();
	/**
	@fn
	@brief デストラクタ
	*/
	~LookAt();
	/**
	@fn
	@brief 初期化
	@param _pos		初期位置
	@param _lookPos	注視点
	@param _up		カメラの上方向
	*/
	void init(const GSvector3& _pos, const GSvector3& _lookPos, const GSvector3& _up = GSvector3(0.f, 1.f, 0.f));
	/**
	@fn
	@brief 更新
	*/
	void update();
	/**
	@fn
	@brief 更新（レンダラー）
	@param _renderer
	*/
	void update(IRenderer* _renderer);
	/**
	@fn
	@brief カメラの移動
	@param _target	ターゲット
	@param _speed	追尾速度
	*/
	void move(const GSvector3 _target, float _speed  = 1);
	/**
	@fn
	@brief カメラの注視点を変更
	@param _target	ターゲット
	@param _speed	追尾速度
	*/
	void lookAt(const GSvector3& _target, float _speed = 1);
	/**
	@fn
	@brief ティルト・パン
	@param _pos		原点
	@param _rotate	角度
	@param _speed	追尾速度
	*/
	void titlePan(const GSvector3& _pos, const GSvector2& _rotate, const GSvector2& _speed = GSvector2(1, 1));
	/**
	@fn
	@brief ドリー
	@param _center		原点
	@param _rotate		角度
	@param _distance	原点とカメラの距離
	@param _speed		追尾速度
	*/
	void dolly(const GSvector3& _center, const GSvector2 _rotate, const float _distance, const GSvector2& _speed = GSvector2(1, 1));
	/**
	@fn
	@brief 地面とのあたり判定
	@param _map	マップ
	*/
	void collisionGround(const Map& _map);
	/**
	@fn
	@brief 後で消す
	*/
	GSmatrix4 matView();
	/**
	@fn
	@brief 後で消す
	*/
	const GSvector3& position();
	/**
	@fn
	@brief 後で消す
	*/
	const GSvector3& lookPosition();
	/**
	@fn
	@brief カメラとの距離
	@return カメラとの距離
	*/
	const float distance(const GSvector3& _other) const;
	/**
	@fn
	@brief カメラのトランスフォームを取得
	@return カメラのトランスフォーム
	@author Matuo
	*/
	const Transform transform() const;
private:
	//地面と当たったか？
	bool isHitGround(const Map& _map, GSvector3* _pos);
private:
	//カメラの位置
	GSvector3 mPos;
	//カメラの注視点
	GSvector3 mLookPos;
	//カメラの位置（オフセット）
	GSvector3 mPosOffset;
	//カメラの注視点（オフセット）
	GSvector3 mLookPosOffset;
	//カメラの上方向
	GSvector3 mUp;
	//モデルビュー変換行列
	GSmatrix4 mMatView;
	//ドリー用格納変数
	GSvector2 mRotateDolly;
	//
	GSvector3 mIntersectPos;
};