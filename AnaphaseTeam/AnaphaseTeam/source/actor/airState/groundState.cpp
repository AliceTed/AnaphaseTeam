/**
* @file groundState.cpp
* @brief 地上にいるときのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/groundState.h"

groundState::groundState()
{

}

groundState::~groundState()
{

}

void groundState::airAction(jumpControl* _jumpAction)
{
	_jumpAction->groundHit();
}