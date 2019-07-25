#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__Profiler

#include "RE/BSScript/IProfilePolicy.h"  // BSScript::IProfilePolicy
#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	namespace SkyrimScript
	{
		class Profiler : public BSScript::IProfilePolicy
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__Profiler;


			virtual ~Profiler();					// 00

			// override (BSScript::IProfilePolicy)
			virtual void	Unk_01(void) override;	// 01
			virtual void	Unk_02(void) override;	// 02
			virtual void	Unk_03(void) override;	// 03
			virtual void	Unk_04(void) override;	// 04


			// members
			mutable BSUniqueLock			unk08;	// 08
			BSTHashMap<UnkKey, UnkValue>	unk10;	// 10
			BSTHashMap<UnkKey, UnkValue>	unk40;	// 40
			BSTHashMap<UnkKey, UnkValue>	unk70;	// 70
			UInt64							unkA0;	// A0
			UInt64							unkA8;	// A8
			UInt64							unkB0;	// B0
			UInt64							unkB8;	// B8
			UInt64							unkC0;	// C0
			UInt64							unkC8;	// C8
			UInt64							unkD0;	// D0
			UInt64							unkD8;	// D8
		};
		STATIC_ASSERT(sizeof(Profiler) == 0xE0);
	}
}
