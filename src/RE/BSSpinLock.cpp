#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	BSSpinLock::BSSpinLock() :
		_threadID(0),
		_lockCount(0)
	{}


	void BSSpinLock::lock()
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (_threadID == myThreadID) {
			++_lockCount;
		} else {
			UInt32 spinCount = 0;
			while (InterlockedCompareExchange(&_threadID, myThreadID, 0)) {
				Sleep(++spinCount > kFastSpinThreshold);
			}

			_lockCount = 1;
			_mm_sfence();
		}
	}


	bool BSSpinLock::try_lock()
	{
		UInt32 myThreadID = GetCurrentThreadId();

		_mm_lfence();
		if (_threadID == myThreadID) {
			++_lockCount;
			return true;
		} else {
			if (InterlockedCompareExchange(&_threadID, myThreadID, 0)) {
				return false;
			} else {
				_lockCount = 1;
				_mm_sfence();
				return true;
			}
		}
	}


	void BSSpinLock::unlock()
	{
		if (--_lockCount == 0) {
			InterlockedCompareExchange(&_threadID, 0, _threadID);
		}
	}
}
