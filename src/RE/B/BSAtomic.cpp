#include "RE/B/BSAtomic.h"

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
//#define NOUSER
#define NONLS
//#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
//#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <Windows.h>

namespace RE
{
	BSSemaphoreBase::BSSemaphoreBase() :
		semaphore()
	{
		stl::memzero(&semaphore);
		semaphore = ::CreateSemaphoreA(nullptr, 0, 40, nullptr);
	}

	BSSemaphoreBase::~BSSemaphoreBase()
	{
		::CloseHandle(semaphore);
		stl::memzero(&semaphore);
	}

	BSSpinLock::BSSpinLock() :
		_owningThread(0),
		_lockCount(0)
	{}

	void BSSpinLock::Lock(std::uint32_t a_pauseAttempts)
	{
		std::uint32_t myThreadID = ::GetCurrentThreadId();

		_mm_lfence();
		if (_owningThread == myThreadID) {
			::_InterlockedIncrement(&_lockCount);
		} else {
			std::uint32_t attempts = 0;
			if (::_InterlockedCompareExchange(&_lockCount, 1, 0)) {
				do {
					++attempts;
					_mm_pause();
					if (attempts >= a_pauseAttempts) {
						std::uint32_t spinCount = 0;
						while (::_InterlockedCompareExchange(&_lockCount, 1, 0)) {
							Sleep(++spinCount < kFastSpinThreshold ? 0 : 1);
						}
						break;
					}
				} while (::_InterlockedCompareExchange(&_lockCount, 1, 0));
				_mm_lfence();
			}

			_owningThread = myThreadID;
			_mm_sfence();
		}
	}

	void BSSpinLock::Unlock()
	{
		std::uint32_t myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (_owningThread == myThreadID) {
			if (_lockCount == 1) {
				_owningThread = 0;
				_mm_mfence();
				::_InterlockedCompareExchange(&_lockCount, 0, 1);
			} else {
				::_InterlockedDecrement(&_lockCount);
			}
		}
	}

	BSReadWriteLock::BSReadWriteLock() :
		_writerThread(0),
		_lock(0)
	{}

	void BSReadWriteLock::LockForRead()
	{
		using func_t = decltype(&BSReadWriteLock::LockForRead);
		REL::Relocation<func_t> func{ Offset::BSReadWriteLock::LockForRead };
		func(this);
	}

	void BSReadWriteLock::UnlockForRead()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockForRead);
		REL::Relocation<func_t> func{ Offset::BSReadWriteLock::UnlockForRead };
		func(this);
	}

	void BSReadWriteLock::LockForWrite()
	{
		using func_t = decltype(&BSReadWriteLock::LockForWrite);
		REL::Relocation<func_t> func{ Offset::BSReadWriteLock::LockForWrite };
		func(this);
	}

	void BSReadWriteLock::UnlockForWrite()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockForWrite);
		REL::Relocation<func_t> func{ Offset::BSReadWriteLock::UnlockForWrite };
		func(this);
	}

	BSSpinLockGuard::BSSpinLockGuard(BSSpinLock& a_lock) :
		_lock(a_lock)
	{
		_lock.Lock();
	}

	BSSpinLockGuard::~BSSpinLockGuard()
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
