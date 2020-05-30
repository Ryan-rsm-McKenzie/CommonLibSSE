#pragma once


namespace RE
{
	template <class T>
	class DoNothingUnhandledPolicy
	{
	public:
		virtual ~DoNothingUnhandledPolicy();  // 00
	};
	STATIC_ASSERT(sizeof(DoNothingUnhandledPolicy<void*>) == 0x8);
}
