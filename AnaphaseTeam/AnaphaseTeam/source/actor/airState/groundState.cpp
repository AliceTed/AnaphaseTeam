/**
* @file groundState.cpp
* @brief 地上にいるときのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/groundState.h"
#include "../../../header/actor/airstate/firstStep.h"

groundState::groundState()
{

}

groundState::~groundState()
{

}

void groundState::start(jumpControl * _jumpAction)
{
	//_jumpAction->groundHit();
}

void groundState::airAction(jumpControl* _jumpAction, Player* _player, float deltaTime)
{
	//_jumpAction->groundHit();
}

void groundState::next(jumpControl * _control)
{
	_control->airActionChange(std::make_shared<firstStep>());
}
