#pragma once
/**
* @file AttackStatus.h
* @brief 攻撃のパラメータ
* @author 松尾裕也
* @date 2016/8/26
*/
#include <gslib.h>
struct AttackStatus
{
	//!攻撃力
	float m_power;
	//!吹っ飛び値(取りあえずベクター3で実装)
	GSvector3 m_blowOff;
};

