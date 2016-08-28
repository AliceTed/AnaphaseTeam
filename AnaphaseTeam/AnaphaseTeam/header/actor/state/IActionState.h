/**
* @file IActionState.h
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
__interface ICharacter;
__interface IActionState
{
public:
	void action(ICharacter* _actor,float deltatime) = 0;
};