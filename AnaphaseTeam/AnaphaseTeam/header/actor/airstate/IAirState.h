/**
* @file IAirState.h
* @brief �󒆎��̃A�N�V�����C���^�[�t�F�C�X
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
class jumpControl;
__interface IAirState
{
public:
	void airAction(jumpControl* _jumpAction) = 0;
};