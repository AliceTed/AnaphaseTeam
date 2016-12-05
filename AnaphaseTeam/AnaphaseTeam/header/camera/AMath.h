/******************************************************
@file	AMath.h
@brief	ŒvZ
@author Yuuho Aritomi
@date	2016/12/02
******************************************************/
#pragma once

#include <gslib.h>

class AMath
{
public:
	/*************************************************
	@brief ‰~ü—¦
	*************************************************/
	static const float PI;

public:
	/*************************************************
	@brief ƒ‰ƒWƒAƒ“‚É•ÏŠ·
	@param[_deg]	Šp“x
	@return			ƒ‰ƒWƒAƒ“’l
	*************************************************/
	static float to_rad(float _deg);


	/*************************************************
	@brief Šp“x‚É•ÏŠ·
	@param[_rad]	ƒ‰ƒWƒAƒ“
	@return			Šp“x
	*************************************************/
	static float to_deg(float _rad);


	/*************************************************
	@brief Šp“x‚Ì³‹K‰»
	@param[_angle]	Šp“x
	@return			-360 ~ 360‚Ü‚Å‚Ì”’l
	*************************************************/
	static float normalizeAngle(float _angle);


	/*************************************************
	@brief Šp“x·‚ğ‹‚ß‚é
	@param[_deg1]	Šp“x‚P	
	@param[_deg2]	Šp“x‚Q
	@return			Šp“x
	*************************************************/
	static float subtractAngle(float _deg1, float _deg2);


	/*************************************************
	@brief ‹…–ÊÀ•W‚ğg‚Á‚½‰ñ“]
	@param[_center]		’†S“_
	@param[_rotate]		‰ñ“]Šp“x
						x : ‹ÂŠp
						y : •ûˆÊŠp
	@param[_distance]	’†S‚©‚ç‚Ì‹——£
	*************************************************/
	static GSvector3 rotate_sphericalCoordinates(
		const GSvector3&	_center,
		const GSvector2&	_rotate,
		const float			_distance
	);
};

