#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyrimScript__ObjectBindPolicy

#include "RE/BSScript/ObjectBindPolicy.h"  // BSScript::ObjectBindPolicy
#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	namespace SkyrimScript
	{
		class ObjectBindPolicy : public BSScript::ObjectBindPolicy
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__ObjectBindPolicy;


			virtual ~ObjectBindPolicy();			// 00

			// override (BSScript::ObjectBindPolicy)
			virtual void	Unk_01(void) override;	// 01
			virtual void	Unk_02(void) override;	// 02
			virtual void	Unk_03(void) override;	// 03
			virtual void	Unk_04(void) override;	// 04
			virtual void	Unk_05(void) override;	// 05
			virtual void	Unk_06(void) override;	// 06
			virtual void	Unk_07(void) override;	// 07
			virtual void	Unk_08(void) override;	// 08
			virtual void	Unk_09(void) override;	// 09
			virtual void	Unk_0A(void) override;	// 0A
			virtual void	Unk_0B(void) override;	// 0B
			virtual void	Unk_0C(void) override;	// 0C


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
