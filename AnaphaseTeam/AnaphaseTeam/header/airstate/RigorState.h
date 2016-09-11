/**
* @file RigorState.h
* @brief 着地硬直時のステート
* @author 渋谷知樹
* @date 2016/08/29
*/

#pragma once
#include "IAirState.h"
#include "jumpControl.h"
#include "../convenient/Timer.h"

class RigorState :public IAirState
{
public:
	RigorState();
	~RigorState();
	/**
	* @fn
	* @brief 着地硬直の時間の設定
	*/
	void start(JumpControl* _control);
	/**
	* @fn
	* @brief 着地のアニメーションと着地時の硬直
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	Timer m_RigorTimer;
};