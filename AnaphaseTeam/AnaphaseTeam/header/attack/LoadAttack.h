#pragma once
/**
* @file LoadAttack.h
* @brief �U���N���X�̓ǂݍ��ݗp�\����
* @author �����T��
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