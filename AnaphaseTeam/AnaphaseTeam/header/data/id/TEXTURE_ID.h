#pragma once
#ifndef _TEXTRUE_ID_H_
#define _TEXTRUE_ID_H_

enum class TEXTURE_ID :unsigned int
{
	WHITE,
	BLACK,
	EXIT,
	GAMESTART,
	PRESSKEY,
	OPTION,
	CURSOR,
	TITLE_ROGO,
	CLEAR,
	OPTION_BACKGROUND,
	PAD_A,
	PAD_B,
	ROGO,
	STAFFROLL,

	SPECIAL_MAIN,
	SPECIAL_ATTACK,
	SPECIAL_RECOVERY,
	SPECIAL_SUPERARMOR,

	GAMEOVER,
	PAUSE_GAMEBACK,
	PAUSE_TITLEBACK,
	UI_STAFF,

	PLAYER_HP,
	PLAYER_HP_GAUGE,
	ENEMY_HP,
	ENEMY_HP_GAUGE,
	SPGAUGE,

	TITLE_MASK,
	NUMBER,
	SIZE
	
};
#endif