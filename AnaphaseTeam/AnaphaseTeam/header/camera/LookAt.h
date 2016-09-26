/**
@file LookAt.h
@brief 後で調べる
@author Yuho Aritomi
@date 2016/09/20 Ver 1.00
*/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	GSvector3 position;	/** @brief カメラの位置 */
	GSvector3 target;	/** @brief 注視点の位置 */
	GSvector3 up;		/** @brief カメラの上側の向き */

	/**
	@brief デフォルトコンストラクタ
	*/
	LookAt(void);

	/**
	@brief コンストラクタ
	@param[_position]	位置
	@param[_target]		注視点
	@param[_up]			カメラの上方向
	*/
	LookAt(const GSvector3 *_position, const GSvector3 *_target, const GSvector3 *_up);
};
