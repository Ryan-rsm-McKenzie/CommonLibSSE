#pragma once

namespace RE
{
	class BSCriticalSection
	{
	public:
		// members
		WinAPI::CRITICAL_SECTION criticalSection;  // 00
	};
	static_assert(sizeof(BSCriticalSection) == 0x28);

	class BSEventFlag
	{
	public:
		// members
		void* event;  // 0
	};
	static_assert(sizeof(BSEventFlag) == 0x8);

	class BSNonReentrantSpinLock
	{
	public:
		// members
		volatile std::uint32_t lock;  // 0
	};
	static_assert(sizeof(BSNonReentrantSpinLock) == 0x4);

	class BSSemaphoreBase
	{
	public:
		BSSemaphoreBase();
		~BSSemaphoreBase();

		// members
		void* semaphore;  // 0
	};
	static_assert(sizeof(BSSemaphoreBase) == 0x8);

	class BSSemaphore : public BSSemaphoreBase
	{
	public:
		BSSemaphore() = default;
		~BSSemaphore() = default;
	};
	static_assert(sizeof(BSSemaphore) == 0x8);

	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000,
		};

		BSSpinLock();

		void Lock(std::uint32_t a_pauseAttempts = 0);
		void Unlock();

	private:
		// members
		volatile std::uint32_t _owningThread;  // 0
		volatile std::uint32_t _lockCount;	   // 4
	};
	static_assert(sizeof(BSSpinLock) == 0x8);

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
		volatile std::uint32_t _writerThread;  // 0
		volatile std::uint32_t _lock;		   // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);

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
	static_assert(sizeof(BSSpinLockGuard) == 0x8);

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
	static_assert(sizeof(BSReadLockGuard) == 0x8);

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
	static_assert(sizeof(BSWriteLockGuard) == 0x8);
}
