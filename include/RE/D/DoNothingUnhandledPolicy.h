#pragma once

namespace RE
{
	template <class T>
	class DoNothingUnhandledPolicy
	{
	public:
		DoNothingUnhandledPolicy() = default;
		virtual ~DoNothingUnhandledPolicy() = default;  // 00
	};
	static_assert(sizeof(DoNothingUnhandledPolicy<void*>) == 0x8);
}
