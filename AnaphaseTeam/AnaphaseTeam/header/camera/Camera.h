/**
@file	Camera.h
@brief	カメラ
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "transform/Transform.h"
#include "camera/LookAt.h";
#include "camera/Perspective.h"

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
	@brief 更新処理
	@param _renderer レンダラー
	*/
	void run(IRenderer* _renderer);
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
	@brief パースペクティブを取得する
	@return パースペクティブ
	*/
	Perspective* perspective();
	/**
	@fn
	@brief ルックアットを取得する
	@return ルックアット
	*/
	LookAt* lookAt();
private:
	//レイを下に飛ばす
	const GSvector3					RAY_DONW;				
	//半径
	const float						R;						
	//視野角と遠近情報
	std::unique_ptr<Perspective>	mPerspective;			
	//カメラの位置情報の集合体
	std::unique_ptr<LookAt>			mLookAt;				
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
};