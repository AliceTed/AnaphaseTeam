/**
* @file IAirState.h
* @brief �󒆎��̃A�N�V�����C���^�[�t�F�C�X
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include <memory>
class JumpControl;
class Player;
class IAirState
{
public:
	virtual ~IAirState() {}
	virtual void start(JumpControl* _control, Player* _player) = 0;
	virtual void airAction(JumpControl* _control, Player* _player, float deltaTime) = 0;
};