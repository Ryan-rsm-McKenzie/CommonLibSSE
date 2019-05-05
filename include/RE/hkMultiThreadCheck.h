#pragma once


namespace RE
{
	class hkMultiThreadCheck
	{
	public:
		enum class AccessType : UInt32
		{
			kIgnore = 0,
			kReadOnly = 1,
			kReadWrite = 2
		};


		enum class ReadMode : UInt32
		{
			kThisObjOnly,
			kRecursive
		};


		enum class MarkedState : UInt32
		{
			kReadOnly = 0xFFFFFFE1,
			kReadOnly_SelfOnly = 0xFFFFFFC1,
			kUnMarked = 0xFFFFFFF1
		};


		UInt32	threadId;		// 0
		SInt32	stackTraceId;	// 4
		UInt16	markCount;		// 8
		UInt16	markBitStack;	// A
	};
	STATIC_ASSERT(sizeof(hkMultiThreadCheck) == 0xC);
}
