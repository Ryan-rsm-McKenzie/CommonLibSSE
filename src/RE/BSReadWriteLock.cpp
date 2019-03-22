#include "RE/BSReadWriteLock.h"  // BSReadWriteLock

#include "skse64/GameTypes.h"  // BSReadWriteLock


namespace RE
{
	BSReadWriteLock::BSReadWriteLock() :
		_threadID(0),
		_lockValue(0)
	{}


	void BSReadWriteLock::LockForRead()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, LockForRead, func_t*);
		func(this);
	}


	void BSReadWriteLock::UnlockRead()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, UnlockRead, func_t*);
		func(this);
	}


	void BSReadWriteLock::LockForWrite()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, LockForWrite, func_t*);
		func(this);
	}


	void BSReadWriteLock::UnlockWrite()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, UnlockWrite, func_t*);
		func(this);
	}


	void BSReadWriteLock::LockForReadAndWrite()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, LockForReadAndWrite, func_t*);
		func(this);
	}


	void BSReadWriteLock::TryLockForWrite()
	{
		using func_t = function_type_t<decltype(&LockForRead)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSReadWriteLock, TryLockForWrite, func_t*);
		func(this);
	}
}
