#pragma once

#include "RE/BSScriptObjectBindPolicy.h"  // BSScript::ObjectBindPolicy
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	namespace SkyrimScript
	{
		class ObjectBindPolicy : public BSScript::ObjectBindPolicy
		{
		public:
			virtual ~ObjectBindPolicy();	// 00


			// members
			UInt64							unk50;	// 50
			UInt64							unk58;	// 58
			BSTHashMap<UnkKey, UnkValue>	unk60;	// 60
			UInt64							unk90;	// 90
			UInt64							unk98;	// 98
			UInt64							unkA0;	// A0
			BSTHashMap<UnkKey, UnkValue>	unkA8;	// A8
		};
		STATIC_ASSERT(sizeof(ObjectBindPolicy) == 0xD8);
	}
}
