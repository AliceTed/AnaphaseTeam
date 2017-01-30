/**
@file
@brief	追尾クラス
@author Yuuho Aritomi
@date	2017/01/27*/
#pragma once

#include <gslib.h>

/**
@class
@brief 追尾クラス
*/
class Tracking
{
public:
	/**
	@fn
	@brief 追尾
	@param _my		動かすオブジェクトの位置
	@param _target	ターゲット
	@param _speed	追尾速度
					[0]		:追尾しない
					[0<x<1]	:ゆっくり追尾
					[1]		:追尾
	@return 結果
	*/
	static GSvector3* tracking(GSvector3* _my, const GSvector3& _target, const float _speed);
};

