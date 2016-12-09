/**
@file	Camera.h
@brief	カメラ
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "../../header/transform/Transform.h"

class SLookAt;		//カメラの位置情報（先頭のＳはきにすんな）
class CameraTarget;	//カメラのターゲット
class Map;			//マップ（std::mapじゃないよ）

class Camera
{

public:
	/**
	@brief コンストラクタ
	*/
	Camera(Map* _map);


	/**
	@brief デストラクタ
	*/
	~Camera();


	/**
	@brief ズーム関係初期化
	*/
	void initialize_zoom(void);


	/**
	@brief 更新処理
	*/
	void update(void);


	/**
	@brief	ティルト・パンカメラワーク
			カメラの位置は固定したまま被写体を見る
	@param[_position_camera]	カメラの位置
	@param[_rotate]				回転
								x回転を固定するとティルト
								y回転を固定するとパン
	@param[_trackingSpeed]		速度
								x：カメラの追尾速度
								y：ターゲットの追尾速度
	*/
	void cameraWork_tilt_pan(
		const GSvector3&	_position_camera,
		const GSvector2&	_rotate,
		const GSvector2&	_trackingSpeed
	);


	/**
	@brief	カメラワーク・ドリー
	ターゲットに追従する
	@param[_position_target]	ターゲット位置
	@param[_rotate]				回転
	@param[_distance]			距離
	@param[_trackingSpeed]		速度
								x：カメラの追尾速度
								y：ターゲットの追尾速度
	*/
	void cameraWork_dolly(
		const GSvector3&	_position_target,
		const GSvector2&	_rotate,
		const float			_distance,
		const GSvector2&	_trackingSpeed
	);


	/**
	@brief プレイヤーの位置を保持
	@param[_target] プレイヤーの位置を入れてね
	*/
	void lookAt_cameraTarget_player(const GSvector3& _target);


	/**
	@brief エネミーの位置を保持
	@param[_target] エネミーの位置を入れてくれ
	*/
	void lookAt_cameraTarget_enemy(const GSvector3& _target);


	/**
	@brief カメラがターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
					[0]			追尾無し
					[0 < x < 1] ディレイありの追尾
					[1]			完全追尾
	*/
	void tracking_position(const GSvector3& _target, float _speed = 1.0f);


	/**
	@brief 注視点がターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
					[0]			追尾無し
					[0 < x < 1] ディレイありの追尾
					[1]			完全追尾
	*/
	void tracking_lookAt(const GSvector3& _target, float _speed = 1.0f);


	/**
	@brief 拡大範囲を設定
	@param[_min] 最小値
	@param[_max] 最大値
	*/
	void zoom_clamp(
		const float _min,
		const float _max
	);


	/**
	@brief ズーム
	@param[_value] 値
	*/
	void zoom(const float _value);


	/**
	@brief ズームイン
	@param[_speed] 速度
	*/
	void zoom_in(const float _speed);


	/**
	@brief ズームアウト
	@param[_speed] 速度
	*/
	void zoom_out(const float _speed);


	/**
	@return カメラターゲット（プレイヤー）
	*/
	const GSvector3& cameraTarget_player(void) const;

	/**
	@return カメラターゲット（エネミー）
	*/
	const GSvector3& cameraTarget_enemy(void) const;

	/**
	@author Matuo
	*/
	//void lookAt(const GSvector3& target, float dir);

	/**
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;

	/**
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;

	/**
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;

	/**
	@author Matuo
	*/
	const Transform transform()const;

	/**
	@return カメラの位置
	*/
	const GSvector3& position(void);

private:
	//カメラの視野角と遠近情報を更新
	void update_perspective(void);

	//カメラの位置情報を更新
	void update_lookAt(void);

	//カメラのズーム値を更新
	void update_zoom(const float _speed);

	//追尾処理更新
	void update_tracking(
		const GSvector3& _position,
		const GSvector3& _lookAt,
		const GSvector2& _trackingSpeed);

	//地面とのあたり判定
	void hit_ground(GSvector3* _position);

	//地面と当たっているか？
	bool isHitGround(GSvector3 * _intersectPos, GSvector3* _position);


private:
	using Perspective = GSvector4;							//４次元ベクトルをパースペクティブとして設定

	static const GSvector3			RAY_DONW;				//レイを下に飛ばす

	static const float				DEF_FOV;				//視野角のデフォルト値
	static const GSvector2			DEF_FOV_CLAMP;			//視野角の範囲のデフォルト値

	Map*							m_map;					//マップ

	Perspective						m_perspective;			//視野角と遠近情報
	GSvector2						m_fov_clamp;			//視野角の範囲
	GSmatrix4						m_mat_projection;		//シェーダー用投射変換行列

	std::unique_ptr<SLookAt>		m_lookAt;				//カメラの位置情報の集合体

	GSvector2						m_rotate_dolly;			//ドリー処理時のディレイ用変数

	std::shared_ptr<CameraTarget>	m_cameraTarget_player;	//プレイヤーの位置
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;	//エネミーの位置
};