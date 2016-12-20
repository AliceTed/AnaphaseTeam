/**
@file	SLookAt.h
@brief	カメラの位置情報用の変数をまとめてるだけ
@author Yuuho Aritomi
@date	2016/12/08
*/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	GSvector3 position;			//**@brief カメラの位置
	GSvector3 position_offset;	//**@brief 位置のオフセット
	GSvector3 target;			//**@brief 注視点
	GSvector3 target_offset;	//**@brief 注視点オフセット
	GSvector3 up;				//**@brief カメラの上方向
	GSmatrix4 mat_view;			//**@brief シェーダー用のモデルビュー変換行列

public:
	/**
	@brief コンストラクタ
	@param[_position]	位置
	@param[_target]		ターゲット
	@param[_up]			カメラの上方向
	*/
	LookAt(GSvector3 _position, GSvector3 _target, GSvector3 _up);

	//デストラクタ
	~LookAt();
};