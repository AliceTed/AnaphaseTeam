/**
@file	E_CameraWorkID.h
@brief	カメラワークＩＤ
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

enum class E_CameraWorkID : int
{
	NONE = 0,		//**@brief なし
	LOCK_ON,		//**@brief ロックオン
	NORMAL,			//**@brief 通常
	DEAD,			//**@brief 死亡
};