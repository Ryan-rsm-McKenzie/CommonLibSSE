#pragma once

#include "RE/IStore.h"  // IStore


namespace RE
{
	namespace SkyrimScript
	{
		class Store : public BSScript::IStore
		{
		public:
			virtual ~Store();	// 00


			// members
			UInt64	unk20;	// 20
			UInt64	unk28;	// 28
			UInt64	unk30;	// 30
			UInt64	unk38;	// 38
		};
		STATIC_ASSERT(sizeof(Store) == 0x40);
	}
}
