#pragma once

namespace RE
{
	struct GArrayDefaultPolicy
	{
	public:
		GArrayDefaultPolicy() :
			capacity(0)
		{}

		GArrayDefaultPolicy(const GArrayDefaultPolicy&) :
			capacity(0)
		{}

		UPInt GetMinCapacity() const { return 0; }
		UPInt GetGranularity() const { return 4; }
		bool  NeverShrinking() const { return false; }

		UPInt GetCapacity() const { return capacity; }
		void  SetCapacity(UPInt a_capacity) { capacity = a_capacity; }

		// members
		UPInt capacity;  // 0
	};
	static_assert(sizeof(GArrayDefaultPolicy) == 0x8);
}
