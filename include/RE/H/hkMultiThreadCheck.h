#pragma once

namespace RE
{
	class hkMultiThreadCheck
	{
	public:
		enum class AccessType
		{
			kIgnore = 0,
			kReadOnly = 1,
			kReadWrite = 2
		};

		enum class ReadMode
		{
			kThisObjOnly,
			kRecursive
		};

		enum class MarkedState : std::uint32_t
		{
			kReadOnly = 0xFFFFFFE1,
			kReadOnly_SelfOnly = 0xFFFFFFC1,
			kUnMarked = 0xFFFFFFF1
		};

		std::uint32_t threadId;      // 0
		std::int32_t  stackTraceId;  // 4
		std::uint16_t markCount;     // 8
		std::uint16_t markBitStack;  // A
	};
	static_assert(sizeof(hkMultiThreadCheck) == 0xC);
}
