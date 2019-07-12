#pragma once


namespace RE
{
	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000,
			kLockWrite = 0x80000000,
			kLockCountMask = 0xFFFFFFF
		};


		BSSpinLock();

		void	LockForRead();
		void	UnlockForRead();
		void	LockForWrite();
		void	UnlockForWrite();

	private:
		// members
		volatile UInt32	_threadID;	// 0
		volatile UInt32	_lockCount;	// 4
	};
	STATIC_ASSERT(sizeof(BSSpinLock) == 0x8);


	class BSReadLockGuard
	{
	public:
		BSReadLockGuard(const BSReadLockGuard&) = delete;
		BSReadLockGuard(BSReadLockGuard&&) = delete;
		explicit BSReadLockGuard(BSSpinLock& a_lock);
		~BSReadLockGuard();

		BSReadLockGuard& operator=(const BSReadLockGuard&) = delete;
		BSReadLockGuard& operator=(BSReadLockGuard&&) = delete;

	private:
		BSSpinLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSReadLockGuard) == 0x8);


	class BSWriteLockGuard
	{
	public:
		BSWriteLockGuard(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard(BSWriteLockGuard&&) = delete;
		explicit BSWriteLockGuard(BSSpinLock& a_lock);
		~BSWriteLockGuard();

		BSWriteLockGuard& operator=(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard& operator=(BSWriteLockGuard&&) = delete;

	private:
		BSSpinLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSWriteLockGuard) == 0x8);
}
