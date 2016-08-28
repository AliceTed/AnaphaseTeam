/**
* @file IAirState.h
* @brief 空中時のアクションインターフェイス
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
class jumpControl;
__interface IAirState
{
public:
	void airAction(jumpControl* _jumpAction) = 0;
};