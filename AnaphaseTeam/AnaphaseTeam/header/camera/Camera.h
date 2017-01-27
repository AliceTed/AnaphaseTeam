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

class LookAt;		//カメラの位置情報（先頭のＳはきにすんな）
class CameraTarget;	//カメラのターゲット
class Map;			//マップ（std::mapじゃないよ）
class IRenderer;
class Zoom;

class Camera
{

public:
	/**
	@fn
	@brief コンストラクタ
	*/
	Camera();
	/**
	@fn
	@brief デストラクタ
	*/
	~Camera();
	/**
	@fn
	@brief リセットオフセット
	*/
	void initializeOffset(void);
	/**
	@fn
	@brief 更新処理
	@param _renderer レンダラー
	*/
	void run(IRenderer* _renderer);
	/**
	@fn
	@brief	ティルト・パンカメラワーク
			カメラの位置は固定したまま被写体を見る
	@param _position_camera		カメラの位置
	@param _rotate				回転
								x回転を固定するとティルト
								y回転を固定するとパン
	@param _trackingSpeed		速度
								x：カメラの追尾速度
								y：ターゲットの追尾速度
	*/
	void tiltPan(
		const GSvector3&	_position_camera,
		const GSvector2&	_rotate,
		const GSvector2&	_trackingSpeed
	);
	/**
	@brief	カメラワーク・ドリー
	ターゲットに追従する
	@param _position_target		ターゲット位置
	@param _rotate				回転
	@param _distance			距離
	@param _trackingSpeed		速度
								x：カメラの追尾速度
								y：ターゲットの追尾速度
	*/
	void dolly(
		const GSvector3&	_position_target,
		const GSvector2&	_rotate,
		const float			_distance,
		const GSvector2&	_trackingSpeed
	);
	/**
	@fn
	@brief プレイヤーの位置を保持
	@param _target	プレイヤーの位置を入れてね
	*/
	void set_cameraTarget_player(const GSvector3& _target);
	/**
	@fn
	@brief エネミーの位置を保持
	@param _target	エネミーの位置を入れてくれ
	*/
	void set_cameraTarget_enemy(const GSvector3& _target);
	/**
	@fn
	@brief プレイヤーの方位角を保持
	@param _direction	方位角
	*/
	void set_direction_player(float _direction);
	/**
	@fn
	@brief カメラがターゲットに追尾
	@param _target	ターゲット
	@param _speed	速度
					[0]			追尾無し
					[0 < x < 1] ディレイありの追尾
					[1]			完全追尾
	*/
	void tracking_position(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief カメラオフセットがターゲットに追尾
	@param _target	ターゲット
	@param _speed 	速度
	[0]			追尾無し
	[0 < x < 1] ディレイありの追尾
	[1]			完全追尾
	*/
	void tracking_positionOffset(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief 注視点がターゲットに追尾
	@param _target	ターゲット
	@param _speed	速度
					[0]			追尾無し
					[0 < x < 1] ディレイありの追尾
					[1]			完全追尾
	*/
	void tracking_lookAt(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief 注視点オフセットがターゲットに追尾
	@param _target  ターゲット
	@param _speed	速度
	[0]			追尾無し
	[0 < x < 1] ディレイありの追尾
	[1]			完全追尾
	*/
	void tracking_lookAtOffset(const GSvector3& _target, float _speed = 1.0f);
	/**
	@fn
	@brief 地面とのあたり判定
	@param _map	マップ
	*/
	void collisionGround(const Map& _map);
	/**
	@fn
	@brief カメラターゲットを取得
	@return カメラターゲット（プレイヤー）
	*/
	const GSvector3& get_cameraTarget_player(void) const;
	/**
	@fn
	@brief カメラターゲットを周夫ｔ九
	@return カメラターゲット（エネミー）
	*/
	const GSvector3& get_cameraTarget_enemy(void) const;
	/**
	@fn
	@brief プレイヤーの方位角
	@return プレイヤーの方位角
	*/
	const float get_direction_player(void) const;
	/**
	@fn
	@brief 映っていないものを調べる
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;
	/**
	@fn
	@brief 
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;
	/**
	@fn
	@brief カメラとの距離
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;
	/**
	@fn
	@brief トランスフォーム
	@author Matuo
	*/
	const Transform transform()const;
	/**
	@brief カメラの位置
	@return カメラの位置
	*/
	const GSvector3& position(void);
	/**
	@fn
	@brief ズーム処理を渡す
	@return ズーム処理
	*/
	Zoom* zoom();
private:
	// カメラオフセットがターゲットに追尾
	void tracking_position_offset(const GSvector3& _target, float _speed = 1.0f);
	// ターゲットオフセットがターゲットに追尾
	void tracking_target_offset(const GSvector3& _target, float _speed = 1.0f);
	//カメラの視野角と遠近情報を更新
	void update_perspective(void);
	//カメラの位置情報を更新
	void update_lookAt(void);
	//追尾処理更新
	void update_tracking(
		const GSvector3& _position,
		const GSvector3& _lookAt,
		const GSvector2& _trackingSpeed);
	//地面と当たっているか？
	bool isHitGround(const Map& _map, GSvector3* _position);
private:
	//レイを下に飛ばす
	const GSvector3					RAY_DONW;				
	//半径
	const float						R;						
	//視野角と遠近情報
	GSvector4						m_perspective;			
	//シェーダー用投射変換行列
	GSmatrix4						m_mat_projection;		
	//カメラの位置情報の集合体
	std::unique_ptr<LookAt>			m_lookAt;				
	//ドリー処理時のディレイ用変数
	GSvector2						m_rotate_dolly;			
	//プレイヤーの位置
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;	
	//エネミーの位置
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;	
	//プレイヤーの方位角
	float							m_direction_player;		
	//保持用
	GSvector3						m_intersectPos;			
	//ズーム
	std::unique_ptr<Zoom>			mZoom;
};