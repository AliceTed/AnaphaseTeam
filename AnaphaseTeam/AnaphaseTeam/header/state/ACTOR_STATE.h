#pragma once

enum class ACTOR_STATE
{
	STAND,
	RUN,
	ATTACK,
	DAMAGE,
	STEP,
	SINGLEJUMP,
	DOUBLEJUMP,
	LIMITFALL,
	LANDINGRIGIDITY,
	SPECIALATTACK,

	ESTAND,
	EATTACK,
	EDEAD,
	EDAMAGE,
	ESLIDE,
	EMOVE,
	ESPAWN,
	EDASH,
	EMOVEBACK,
	ETHINK
};