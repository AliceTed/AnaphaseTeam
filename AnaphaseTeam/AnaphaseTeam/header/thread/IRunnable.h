#pragma once

//スレッド実行インターフェイス
class IRunnable
{
public:
	virtual ~IRunnable() {}
	virtual void run() = 0;
};