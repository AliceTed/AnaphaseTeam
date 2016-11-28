#pragma once
/**
* @file LoadAttack.h
* @brief 攻撃クラスの読み込み用構造体
* @author 松尾裕也
* @date 2016/11/27
*/
#include "Attack.h"
struct LoadAttack
{
	ATTACK_TYPE m_type;
	Attack m_attack;
	LoadAttack()
		:m_attack(AttackStatus(),ANIMATION_ID::ATTACK,ATTACK_TYPE::End, ATTACK_TYPE::End),
		m_type(ATTACK_TYPE::End)
	{}
};