/**
* @file firstStep.h
* @brief ジャンプの準備ステート
* @author 渋谷知樹
* @date 2016/09/21
*/
#pragma once
#include "IAirState.h"
class PreparationState :public IAirState
{
public:
	PreparationState();
	~PreparationState();
	/**
	* @fn
	* @brief 
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief 
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
};