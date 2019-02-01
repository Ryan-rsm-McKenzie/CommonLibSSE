#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	BSSpinLock::BSSpinLock() :
		threadID(0),
		lockCount(0)
	{}


	void BSSpinLock::Lock()
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (threadID == myThreadID) {
			++lockCount;
		} else {
			UInt32 spinCount = 0;
			while (InterlockedCompareExchange(&threadID, myThreadID, 0)) {
				Sleep(++spinCount > kFastSpinThreshold);
			}

			lockCount = 1;
			_mm_sfence();
		}
	}


	bool BSSpinLock::TryToLock()
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (threadID == myThreadID) {
			++lockCount;
			return true;
		} else {
			if (InterlockedCompareExchange(&threadID, myThreadID, 0)) {
				return false;
			} else {
				lockCount = 1;
				_mm_sfence();
				return true;
			}
		}
	}


	void BSSpinLock::Unlock()
	{
		if (--lockCount == 0) {
			InterlockedCompareExchange(&threadID, 0, threadID);
		}
	}


	void BSSpinLock::Release()
	{
		Unlock();
	}
}
