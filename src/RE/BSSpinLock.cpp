#include "RE/BSSpinLock.h"  // BSSpinLock

#include "skse64/GameTypes.h"  // BSReadWriteLock


namespace RE
{
	BSSpinLock::BSSpinLock() :
		_threadID(0),
		_lockCount(0)
	{}


	void BSSpinLock::Lock(UInt32 a_pauseAttempts)
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (_threadID == myThreadID) {
			InterlockedIncrement(&_lockCount);
		} else {
			UInt32 attempts = 0;
			if (InterlockedCompareExchange(&_lockCount, 1, 0)) {
				do {
					++attempts;
					_mm_pause();
					if (attempts >= a_pauseAttempts) {
						UInt32 spinCount = 0;
						while (InterlockedCompareExchange(&_lockCount, 1, 0)) {
							Sleep(++spinCount < kFastSpinThreshold ? 0 : 1);
						}
						break;
					}
				} while (InterlockedCompareExchange(&_lockCount, 1, 0));
				_mm_lfence();
			}

			_threadID = myThreadID;
			_mm_sfence();
		}
	}


	void BSSpinLock::Unlock()
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (_threadID == myThreadID) {
			if (_lockCount == 1) {
				_threadID = 0;
				_mm_mfence();
				InterlockedCompareExchange(&_lockCount, 0, 1);
			} else {
				InterlockedDecrement(&_lockCount);
			}
		}
	}


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


	BSLockGuard::BSLockGuard(BSSpinLock& a_lock) :
		_lock(a_lock)
	{
		_lock.Lock();
	}


	BSLockGuard::~BSLockGuard()
	{
		_lock.Unlock();
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
