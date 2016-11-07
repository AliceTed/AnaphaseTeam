/**
@file 
.h
@brief カメラ
@author Yuuoh Aritomi : Matuo
@date 2016/09/23 Ver1.00
*/
#pragma once

#include <gslib.h>
#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"
class Camera
{
	Perspective m_perspective;
	LookAt m_look_at;

	//float m_near;
	//float m_far;

	float range_Position;
	float range_Eye;
	GSvector3 offset;
	GSvector3 position;

public:
	/**
	@brief デフォルトコンストラクタ
	*/
	Camera(void);

	/**
	@brief コンストラクタ
	*/
	Camera(const Perspective* _perspective, const GSvector3* _position);

	/**
	@brief コンストラクタ
	*/
	Camera(float range_Position, float range_Eye, const GSvector3& offset);

	/**
	@brief デストラクタ
	*/
	~Camera();

	/**
	@brief 更新処理
	@author Aritomi
	*/
	void update(void);

	/**
	@brief 指定した位置に移動する
	@author Aritomi
	*/
	void move(const GSvector3* _position);

	/**
	@brief カメラが見ている位置を設定する
	@author Aritomi
	*/
	void look_at(const GSvector3* _target);

	/** 
	@brief パースペクティブ値を返す
	@author Aritomi
	*/
	const Perspective PERSPECTIVE(void) const
	{
		return m_perspective;
	}

	/**
	@brief 現在のカメラの位置を返す
	@author Aritomi
	*/
	const GSvector3 POSITION(void) const
	{
		return m_look_at.position;
	}

	/**
	@brief 現在の注視点の位置を返す
	@author Aritomi
	*/
	const GSvector3 TARGET(void) const
	{
		return m_look_at.target;
	}

	/**
	@author Matuo
	*/
	void lookAt(const GSvector3& target, float dir);

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

	//取りあえず
	const Transform transform()const;
private:
	void update_perspective(const Perspective*) const;	// 遠近法設定を更新
	
	void update_look_at(const LookAt*) const;			// 表示位置を更新
};