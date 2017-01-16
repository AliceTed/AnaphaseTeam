#pragma once
#include "IRunnable.h"
class Thread:public IRunnable
{
public:
	Thread(IRunnable* _runnable=nullptr);
	virtual ~Thread();
	//�X���b�h�J�n
	virtual void start();
	//�X���b�h�J�n
	virtual void start(IRunnable* _runnable);
	//�X���b�h�I����҂�
	void join();
	//�X���[�v
	static void sleep(unsigned int _millsecond);
	//�X���b�h�̎��s
	virtual void run();
private:
	//�R�[���o�b�N�֐�
	static void callback(void* _runnable);
private:
	void* m_handle;
	IRunnable* m_runnable;
};