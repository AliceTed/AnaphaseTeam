/**
* @file IAirState.h
* @brief �󒆎��̃A�N�V�����C���^�[�t�F�C�X
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
class JumpControl;
class Player;
class IAirState
{
public:
	virtual ~IAirState() {}
	virtual void start(JumpControl* _jumpAction) = 0;
	virtual void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime) = 0;
	virtual void next(JumpControl* _control) = 0;
};