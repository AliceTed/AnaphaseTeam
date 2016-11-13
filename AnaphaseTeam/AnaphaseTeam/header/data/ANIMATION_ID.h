#pragma once
#ifndef _ANIMATION_ID_H_
#define _ANIMATION_ID_H_

enum class ANIMATION_ID :unsigned int
{
	STAND,
	RUN,
	JUMPUP = 4,
	LANDING,
	AVOID = 9,
	DAMAGE = 11,
	ATTACK = 17,
	ATTACK2,
	ATTACK3,
	ATTACK4,
	ATTACK5,
	ATTACK6,
	FATTACK,

	SIZE = 99
};

#endif