#pragma once

namespace RE
{
	template <std::int32_t MinCapacity = 0, std::int32_t Granularity = 4, bool NeverShrink = false>
	struct GArrayConstPolicy
	{
	public:
		using SelfType = GArrayConstPolicy<MinCapacity, Granularity, NeverShrink>;

		GArrayConstPolicy() :
			capacity(0)
		{}

		GArrayConstPolicy(const SelfType&) :
			capacity(0)
		{}

		UPInt GetMinCapacity() const { return MinCapacity; }
		UPInt GetGranularity() const { return Granularity; }
		bool  NeverShrinking() const { return NeverShrink; }

		UPInt GetCapacity() const { return capacity; }
		void  SetCapacity(UPInt a_capacity) { capacity = a_capacity; }

		// members
		UPInt capacity;  // 0
	};
	static_assert(sizeof(GArrayDefaultPolicy) == 0x8);
}
