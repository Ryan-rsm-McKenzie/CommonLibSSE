#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTTuple.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			struct VDescTable
			{
			public:
				explicit VDescTable(std::uint16_t a_numParams, std::uint16_t a_numLocals);


				// members
				SimpleArray<BSTTuple<BSFixedString, TypeInfo>> entries;		  // 00
				std::uint16_t								   paramCount;	  // 08
				std::uint16_t								   totalEntries;  // 0A
				std::uint32_t								   pad0C;		  // 0C
			};
			static_assert(sizeof(VDescTable) == 0x10);
		}
	}
}
