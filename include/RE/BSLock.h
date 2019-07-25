#pragma once


namespace RE
{
	class BSUniqueLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000,
		};


		BSUniqueLock();

		void	Lock(UInt32 a_pauseAttempts = 0);
		void	Unlock();

	private:
		// members
		volatile UInt32	_threadID;	// 0
		volatile UInt32	_lockCount;	// 4
	};
	STATIC_ASSERT(sizeof(BSUniqueLock) == 0x8);


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
		volatile UInt32	_threadID;	// 0
		volatile UInt32	_lockCount;	// 4
	};
	STATIC_ASSERT(sizeof(BSReadWriteLock) == 0x8);


	class BSUniqueLockGuard
	{
	public:
		BSUniqueLockGuard() = delete;
		BSUniqueLockGuard(const BSUniqueLockGuard&) = delete;
		BSUniqueLockGuard(BSUniqueLockGuard&&) = delete;
		explicit BSUniqueLockGuard(BSUniqueLock& a_lock);
		~BSUniqueLockGuard();

		BSUniqueLockGuard& operator=(const BSUniqueLockGuard&) = delete;
		BSUniqueLockGuard& operator=(BSUniqueLockGuard&&) = delete;

	private:
		BSUniqueLock& _lock;	// 0
	};
	STATIC_ASSERT(sizeof(BSUniqueLockGuard) == 0x8);


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
