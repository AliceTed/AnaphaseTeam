#pragma once
/**
* @file LoadAttack.h
* @brief 攻撃クラスの読み込み用構造体
* @author 松尾裕也
* @date 2016/11/27
*/
#include "AttackParameter.h"
struct LoadAttack
{
	std::string selfID;
	AttackParameter parameter;
	LoadAttack()
		:selfID(""),
		parameter() {}
};