#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSCore/BSTTuple.h"
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
				explicit VDescTable(UInt16 a_numParams, UInt16 a_numLocals);


				// members
				SimpleArray<BSTTuple<BSFixedString, TypeInfo>> entries;		  // 00
				UInt16										   paramCount;	  // 08
				UInt16										   totalEntries;  // 0A
				UInt32										   pad0C;		  // 0C
			};
			STATIC_ASSERT(sizeof(VDescTable) == 0x10);
		}
	}
}
