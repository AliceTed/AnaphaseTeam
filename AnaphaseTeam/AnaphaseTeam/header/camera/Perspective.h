/**
@file Perspective.h
@brief 遠近法
@author Yuho Artiomi
@data 2016-08-27 Ver1.00
*/
#pragma once

class Perspective
{
public:
	float fov;		/** @brief 視野 */
	float aspect;	/** @brief 面 */
	float near;		/** @brief 近い距離 */
	float far;		/** @brief 遠い距離 */

	/**
	@brief デフォルトコンストラクタ
	*/
	Perspective(void);

	/**
	@brief コンストラクタ
	*/
	Perspective(const float _fov, const float _aspect, const float _near, const float _far);
};