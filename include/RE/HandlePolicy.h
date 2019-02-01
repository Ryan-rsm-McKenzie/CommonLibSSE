#pragma once

#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy


namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy : public BSScript::IObjectHandlePolicy
		{
		public:
			virtual ~HandlePolicy();	// 00


			// members
			UInt64							unk08;	// 08
			BSTHashMap<UnkKey, UnkValue>	unk10;	// 10
			BSTHashMap<UnkKey, UnkValue>	unk40;	// 40
		};
		STATIC_ASSERT(sizeof(HandlePolicy) == 0x70);
	}
}
