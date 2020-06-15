#pragma once


namespace RE
{
	template <class T>
	class DoNothingUnhandledPolicy
	{
	public:
		DoNothingUnhandledPolicy() = default;
		virtual ~DoNothingUnhandledPolicy() = default;	// 00
	};
	STATIC_ASSERT(sizeof(DoNothingUnhandledPolicy<void*>) == 0x8);
}
