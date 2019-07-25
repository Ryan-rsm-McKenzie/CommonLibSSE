#include "RE/BSLock.h"

#include "skse64/GameTypes.h"  // BSReadWriteLock


namespace RE
{
	BSUniqueLock::BSUniqueLock() :
		_threadID(0),
		_lockCount(0)
	{}


	void BSUniqueLock::Lock(UInt32 a_pauseAttempts)
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


	void BSUniqueLock::Unlock()
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


	BSReadWriteLock::BSReadWriteLock() :
		_threadID(0),
		_lockCount(0)
	{}


	void BSReadWriteLock::LockForRead()
	{
		using func_t = function_type_t<decltype(&BSReadWriteLock::LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, LockForRead, func_t*);
		func(this);
	}


	void BSReadWriteLock::UnlockForRead()
	{
		using func_t = function_type_t<decltype(&BSReadWriteLock::UnlockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, UnlockRead, func_t*);
		func(this);
	}


	void BSReadWriteLock::LockForWrite()
	{
		using func_t = function_type_t<decltype(&BSReadWriteLock::LockForWrite)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, LockForWrite, func_t*);
		func(this);
	}


	void BSReadWriteLock::UnlockForWrite()
	{
		using func_t = function_type_t<decltype(&BSReadWriteLock::UnlockForWrite)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, UnlockWrite, func_t*);
		func(this);
	}


	BSUniqueLockGuard::BSUniqueLockGuard(BSUniqueLock& a_lock) :
		_lock(a_lock)
	{
		_lock.Lock();
	}


	BSUniqueLockGuard::~BSUniqueLockGuard()
	{
		_lock.Unlock();
	}


	BSReadLockGuard::BSReadLockGuard(BSReadWriteLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForRead();
	}


	BSReadLockGuard::~BSReadLockGuard()
	{
		_lock.UnlockForRead();
	}


	BSWriteLockGuard::BSWriteLockGuard(BSReadWriteLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForWrite();
	}


	BSWriteLockGuard::~BSWriteLockGuard()
	{
		_lock.UnlockForWrite();
	}
}
