#pragma once
/**
* @file LoadAttack.h
* @brief �U���N���X�̓ǂݍ��ݗp�\����
* @author �����T��
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