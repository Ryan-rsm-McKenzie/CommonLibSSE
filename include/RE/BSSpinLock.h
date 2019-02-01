#pragma once


namespace RE
{
	class BSSpinLock
	{
	public:
		enum
		{
			kFastSpinThreshold = 10000
		};


		BSSpinLock();

		void	Lock();
		bool	TryToLock();
		void	Unlock();
		void	Release();


	private:
		// members
		volatile UInt32	threadID;	// 0
		volatile UInt32	lockCount;	// 4
	};
	STATIC_ASSERT(sizeof(BSSpinLock) == 0x8);
}
