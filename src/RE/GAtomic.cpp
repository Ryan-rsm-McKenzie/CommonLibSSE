#include "RE/GAtomic.h"


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


	GLock::GLock(UInt32 a_spinCount)
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
