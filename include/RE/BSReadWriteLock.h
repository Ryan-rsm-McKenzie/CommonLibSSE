#pragma once


namespace RE
{
	class BSReadWriteLock
	{
	public:
		BSReadWriteLock();

		void	LockForRead();
		void	UnlockRead();
		void	LockForWrite();
		void	UnlockWrite();
		void	LockForReadAndWrite();
		void	TryLockForWrite();

	protected:
		enum
		{
			kFastSpinThreshold = 10000,
			kLockWrite = 0x80000000,
			kLockCountMask = 0xFFFFFFF
		};


		volatile SInt32	_threadID;	// 00
		volatile UInt32	_lockValue;	// 04
	};
	STATIC_ASSERT(sizeof(BSReadWriteLock) == 0x8);
}
