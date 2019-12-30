#pragma once


namespace RE
{
	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000,
		};


		BSSpinLock();

		void	Lock(UInt32 a_pauseAttempts = 0);
		void	Unlock();

	private:
		// members
		volatile UInt32	_owningThread;	// 0
		volatile UInt32	_lockCount;		// 4
	};
	STATIC_ASSERT(sizeof(BSSpinLock) == 0x8);


	class BSReadWriteLock
	{
	public:
		enum
		{
			kLockWrite = 0x80000000,
			kLockCountMask = 0xFFFFFFF
		};


		BSReadWriteLock();

		void	LockForRead();
		void	UnlockForRead();
		void	LockForWrite();
		void	UnlockForWrite();

	private:
		// members
		volatile UInt32	_writerThread;	// 0
		volatile UInt32	_lock;			// 4
	};
	STATIC_ASSERT(sizeof(BSReadWriteLock) == 0x8);


	class BSSpinLockGuard
	{
	public:
		BSSpinLockGuard() = delete;
		BSSpinLockGuard(const BSSpinLockGuard&) = delete;
		BSSpinLockGuard(BSSpinLockGuard&&) = delete;
		explicit BSSpinLockGuard(BSSpinLock& a_lock);
		~BSSpinLockGuard();

		BSSpinLockGuard& operator=(const BSSpinLockGuard&) = delete;
		BSSpinLockGuard& operator=(BSSpinLockGuard&&) = delete;

	private:
		BSSpinLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSSpinLockGuard) == 0x8);


	class BSReadLockGuard
	{
	public:
		BSReadLockGuard() = delete;
		BSReadLockGuard(const BSReadLockGuard&) = delete;
		BSReadLockGuard(BSReadLockGuard&&) = delete;
		explicit BSReadLockGuard(BSReadWriteLock& a_lock);
		~BSReadLockGuard();

		BSReadLockGuard& operator=(const BSReadLockGuard&) = delete;
		BSReadLockGuard& operator=(BSReadLockGuard&&) = delete;

	private:
		BSReadWriteLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSReadLockGuard) == 0x8);


	class BSWriteLockGuard
	{
	public:
		BSWriteLockGuard() = delete;
		BSWriteLockGuard(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard(BSWriteLockGuard&&) = delete;
		explicit BSWriteLockGuard(BSReadWriteLock& a_lock);
		~BSWriteLockGuard();

		BSWriteLockGuard& operator=(const BSWriteLockGuard&) = delete;
		BSWriteLockGuard& operator=(BSWriteLockGuard&&) = delete;

	private:
		BSReadWriteLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSWriteLockGuard) == 0x8);
}
