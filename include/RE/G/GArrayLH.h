#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GArrayBase.h"
#include "RE/G/GArrayData.h"
#include "RE/G/GArrayDefaultPolicy.h"
#include "RE/G/GStats.h"

namespace RE
{
	template <class T, std::uint32_t SID = GStatGroup::kGStat_Default_Mem, class SizePolicy = GArrayDefaultPolicy>
	class GArrayLH : public GArrayBase<GArrayData<T, GAllocatorLH<T, SID>, SizePolicy>>
	{
	public:
		using ValueType = T;
		using AllocatorType = GAllocatorLH<T, SID>;
		using SizePolicyType = SizePolicy;
		using SelfType = GArrayLH<T, SID, SizePolicy>;
		using BaseType = GArrayBase<GArrayData<T, GAllocatorLH<T, SID>, SizePolicy>>;

		GArrayLH() :
			BaseType()
		{}

		GArrayLH(std::int32_t a_size) :
			BaseType(a_size)
		{}

		GArrayLH(const SizePolicyType& a_policy) :
			BaseType()
		{
			SetSizePolicy(a_policy);
		}

		GArrayLH(const SelfType& a_array) :
			BaseType(a_array)
		{}

		const SelfType& operator=(const SelfType& a_array)
		{
			BaseType::operator=(a_array);
			return *this;
		}
	};
	static_assert(sizeof(GArrayLH<void*>) == 0x18);
}
