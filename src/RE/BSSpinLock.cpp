#include "RE/BSSpinLock.h"  // BSSpinLock

#include "skse64/GameTypes.h"  // BSReadWriteLock


namespace RE
{
	BSSpinLock::BSSpinLock() :
		_threadID(0),
		_lockCount(0)
	{}


	void BSSpinLock::LockForRead()
	{
		using func_t = function_type_t<decltype(&BSSpinLock::LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(BSReadWriteLock, LockForRead, func_t*);
		func(this);
	}


	void BSSpinLock::UnlockForRead()
	{
		using func_t = function_type_t<decltype(&BSSpinLock::UnlockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(BSReadWriteLock, UnlockRead, func_t*);
		func(this);
	}


	void BSSpinLock::LockForWrite()
	{
		using func_t = function_type_t<decltype(&BSSpinLock::LockForWrite)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(BSReadWriteLock, LockForWrite, func_t*);
		func(this);
	}


	void BSSpinLock::UnlockForWrite()
	{
		using func_t = function_type_t<decltype(&BSSpinLock::UnlockForWrite)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(BSReadWriteLock, UnlockWrite, func_t*);
		func(this);
	}


	BSReadLockGuard::BSReadLockGuard(BSSpinLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForRead();
	}


	BSReadLockGuard::~BSReadLockGuard()
	{
		_lock.UnlockForRead();
	}


	BSWriteLockGuard::BSWriteLockGuard(BSSpinLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForWrite();
	}


	BSWriteLockGuard::~BSWriteLockGuard()
	{
		_lock.UnlockForWrite();
	}
}
