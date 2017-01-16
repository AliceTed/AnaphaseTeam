#pragma once
#include "IRunnable.h"
class Thread:public IRunnable
{
public:
	Thread(IRunnable* _runnable=nullptr);
	virtual ~Thread();
	//スレッド開始
	virtual void start();
	//スレッド開始
	virtual void start(IRunnable* _runnable);
	//スレッド終了を待つ
	void join();
	//スリープ
	static void sleep(unsigned int _millsecond);
	//スレッドの実行
	virtual void run();
private:
	//コールバック関数
	static void callback(void* _runnable);
private:
	void* m_handle;
	IRunnable* m_runnable;
};