#include "../../header/thread/Thread.h"
#include <Windows.h>
#include <process.h>
Thread::Thread(IRunnable * _runnable)
	:m_handle(nullptr),
	m_runnable(_runnable)
{
	if (m_runnable == nullptr)
	{
		m_runnable = this;
	}
}

Thread::~Thread()
{
}

void Thread::start()
{
	m_handle = reinterpret_cast<void*>(::_beginthread(callback, 0, this));
}

void Thread::start(IRunnable * _runnable)
{
	m_runnable = _runnable;
	start();
}

void Thread::join()
{
	if (m_handle == nullptr)return;
	::WaitForSingleObject(m_handle, INFINITE);
}

void Thread::sleep(unsigned int _millsecond)
{
	::Sleep(_millsecond);
}

void Thread::run()
{
}

void Thread::callback(void * _runnable)
{
	Thread* thread = reinterpret_cast<Thread*>(_runnable);
	//スレッドの処理開始
	thread->m_runnable->run();
	//スレッドハンドルを無効にする
	thread->m_handle = nullptr;
}
