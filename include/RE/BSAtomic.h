#pragma once


namespace RE
{
	class BSCriticalSection
	{
	public:
		// members
		CRITICAL_SECTION criticalSection;  // 00
	};
	STATIC_ASSERT(sizeof(BSCriticalSection) == 0x28);


	class BSEventFlag
	{
	public:
		// members
		HANDLE event;  // 0
	};
	STATIC_ASSERT(sizeof(BSEventFlag) == 0x8);


	class BSNonReentrantSpinLock
	{
	public:
		// members
		volatile UInt32 lock;  // 0
	};
	STATIC_ASSERT(sizeof(BSNonReentrantSpinLock) == 0x4);


	class BSSemaphoreBase
	{
	public:
		BSSemaphoreBase();
		~BSSemaphoreBase();


		// members
		HANDLE semaphore;  // 0
	};
	STATIC_ASSERT(sizeof(BSSemaphoreBase) == 0x8);


	class BSSemaphore : public BSSemaphoreBase
	{
	public:
		BSSemaphore() = default;
		~BSSemaphore() = default;
	};
	STATIC_ASSERT(sizeof(BSSemaphore) == 0x8);


	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000,
		};


		BSSpinLock();

		void Lock(UInt32 a_pauseAttempts = 0);
		void Unlock();

	private:
		// members
		volatile UInt32 _owningThread;	// 0
		volatile UInt32 _lockCount;		// 4
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

		void LockForRead();
		void UnlockForRead();
		void LockForWrite();
		void UnlockForWrite();

	private:
		// members
		volatile UInt32 _writerThread;	// 0
		volatile UInt32 _lock;			// 4
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
		BSReadWriteLock& _lock;	 // 0
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
		BSReadWriteLock& _lock;	 // 0
	};
	STATIC_ASSERT(sizeof(BSWriteLockGuard) == 0x8);
}
