/**
* @file groundState.cpp
* @brief ���n�̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../header/airstate/groundState.h"
#include "../../header/airstate/PreparationState.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/subAction/JumpControl.h"
GroundState::GroundState()
	:m_RigorTimer(0.3f)
{

}
GroundState::~GroundState()
{

}
void GroundState::start(JumpControl * _control, Player* _player)
{
	m_RigorTimer.initialize();
}
void GroundState::airAction(JumpControl* _control, Player* _player, float deltaTime)
{
	_player->jumpMotion(*_control,ANIMATION_ID::LANDING);
	m_RigorTimer.update(deltaTime);
	if (m_RigorTimer.isEnd())
	{
		_control->end();
	}
}