#pragma once

//�X���b�h���s�C���^�[�t�F�C�X
class IRunnable
{
public:
	virtual ~IRunnable() {}
	virtual void run() = 0;
};