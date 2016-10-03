#pragma once
#ifndef _ANIMATION_ID_H_
#define _ANIMATION_ID_H_

enum class ANIMATION_ID :unsigned int
{
	STAND,
	RUN,
	JUMPUP = 4,
	LANDING,
	AVOID=9,
	ATTACK = 17,
	ATTACK2,
	ATTACK3,
	ATTACK4,
	GUN,
	CHARGEATTACK,

	SIZE
};

#endif