#pragma once


namespace RE
{
	class BSSpinLock
	{
	public:
		enum { kFastSpinThreshold = 10000 };


		BSSpinLock();

		void	lock();
		bool	try_lock();
		void	unlock();

	private:
		// members
		volatile UInt32	_threadID;	// 0
		volatile UInt32	_lockCount;	// 4
	};
	STATIC_ASSERT(sizeof(BSSpinLock) == 0x8);
}
