#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	namespace SkyrimScript
	{
		class FragmentSystem
		{
		public:
			BSTHashMap<UnkKey, UnkValue> unk000;  // 000
			mutable BSSpinLock           unk030;  // 030
			BSTHashMap<UnkKey, UnkValue> unk038;  // 038
			mutable BSSpinLock           unk068;  // 068
			BSTHashMap<UnkKey, UnkValue> unk070;  // 070
			mutable BSSpinLock           unk0A0;  // 0A0
			BSTHashMap<UnkKey, UnkValue> unk0A8;  // 0A8
			mutable BSSpinLock           unk0D8;  // 0D8
			BSTHashMap<UnkKey, UnkValue> unk0E0;  // 0E0
			mutable BSSpinLock           unk110;  // 110
		};
		static_assert(sizeof(FragmentSystem) == 0x118);
	}
}
