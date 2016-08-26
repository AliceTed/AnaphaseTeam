#pragma once
/**
* @file SubActionManager.h
* @brief サブアクションをまとめて管理するクラス
* @author 松尾裕也
* @date 日付 2016/8/26
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