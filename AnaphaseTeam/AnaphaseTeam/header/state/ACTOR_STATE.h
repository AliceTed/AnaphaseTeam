#pragma once

enum class ACTOR_STATE
{
	STAND,
	RUN,
	ATTACK,
	DAMAGE,
	STEP,
	HOMING,
	SINGLEJUMP,
	DOUBLEJUMP,
	LIMITFALL,
	LANDINGRIGIDITY,
	SPECIALATTACK,

	ESTAND,
	EATTACK,
	ESECOUNDATTACK,
	EDEAD,
	EDAMAGE,
	ESLIDE,
	EMOVE,
	ESPAWN,
	EDASH,
	EMOVEBACK,
	ETHINK
};