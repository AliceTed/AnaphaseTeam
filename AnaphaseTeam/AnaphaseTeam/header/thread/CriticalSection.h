#pragma once
#include <Windows.h>
class CriticalSection
{
public:
	CriticalSection();
	~CriticalSection();
	//�J�n
	void enter();
	//�I��
	void leave();

	class Lock
	{
	public:
		Lock(CriticalSection& _section);
		~Lock();

	private:
		CriticalSection& m_section;
	};
private:
	CRITICAL_SECTION m_section;
};