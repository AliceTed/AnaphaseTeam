#pragma once
/**
* @file SubActionManager.h
* @brief �T�u�A�N�V�������܂Ƃ߂ĊǗ�����N���X
* @author �����T��
* @date ���t 2016/8/26
*/
#include "TestJump.h"
#include "TestChainMove.h"
class SubActionManager
{
public:
	SubActionManager();
	~SubActionManager();

	void action(Player* _player, float deltaTime);
	void actionStart(Player* _player);

	void groundHit();
private:
	TestChainMove m_chainMove;
	TestJump m_jump;
};