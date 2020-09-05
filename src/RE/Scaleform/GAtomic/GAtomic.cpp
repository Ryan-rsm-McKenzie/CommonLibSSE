#include "RE/Scaleform/GAtomic/GAtomic.h"


namespace RE
{
	GLock::Locker::Locker(GLock* a_lock)
	{
		lock = a_lock;
		lock->Lock();
	}


	GLock::Locker::~Locker()
	{
		lock->Unlock();
	}


	GLock::GLock(std::uint32_t a_spinCount)
	{
		::InitializeCriticalSectionAndSpinCount(&cs, a_spinCount);
	}


	GLock::~GLock()
	{
		::DeleteCriticalSection(&cs);
	}


	void GLock::Lock()
	{
		::EnterCriticalSection(&cs);
	}


	void GLock::Unlock()
	{
		::LeaveCriticalSection(&cs);
	}
}
