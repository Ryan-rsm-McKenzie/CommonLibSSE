#pragma once

namespace RE
{
	template <class T, class Val>
	class ActorSpeedChannel
	{
	public:
		// members
		std::uint32_t unk00;  // 00
		Val           val;    // 04
		T*            type;   // ??
	};
	static_assert(sizeof(ActorSpeedChannel<void, float>) == 0x10);
}
