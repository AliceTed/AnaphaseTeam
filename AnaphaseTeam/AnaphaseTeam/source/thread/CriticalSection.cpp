#include "../../header/thread/CriticalSection.h"

CriticalSection::CriticalSection()
{
	::InitializeCriticalSection(&m_section);
}

CriticalSection::~CriticalSection()
{
	::DeleteCriticalSection(&m_section);
}

void CriticalSection::enter()
{
	::EnterCriticalSection(&m_section);
}

void CriticalSection::leave()
{
	::LeaveCriticalSection(&m_section);
}


CriticalSection::Lock::Lock(CriticalSection & _section)
	:m_section(_section)
{
	m_section.enter();
}

CriticalSection::Lock::~Lock()
{
	m_section.leave();
}

