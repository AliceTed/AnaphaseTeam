/*********************************************************************
@file	E_CameraWorkID.h
@brief	カメラワークＩＤ
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

enum class E_CameraWorkID : int
{
	NONE = -1,
	LOCK_ON = 0,
	NORMAL,
	DEAD,
};