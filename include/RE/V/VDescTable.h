#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTTuple.h"
#include "RE/M/MemoryManager.h"
#include "RE/T/TypeInfo.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			struct VDescTable
			{
			public:
				explicit inline VDescTable(std::uint16_t a_numParams, std::uint16_t a_numLocals) :
					entries(static_cast<std::size_t>(a_numParams + a_numLocals)),
					paramCount(a_numParams),
					totalEntries(static_cast<std::uint16_t>(a_numParams + a_numLocals))
				{}

				// members
				SimpleArray<BSTTuple<BSFixedString, TypeInfo>> entries;       // 00
				std::uint16_t                                  paramCount;    // 08
				std::uint16_t                                  totalEntries;  // 0A
				std::uint32_t                                  pad0C{ 0 };    // 0C
			};
			static_assert(sizeof(VDescTable) == 0x10);
		}
	}
}
