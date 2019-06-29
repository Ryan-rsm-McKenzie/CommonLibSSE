#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__SimpleAllocMemoryPagePolicy

#include "RE/BSScript/IMemoryPagePolicy.h"  // BSScript::IMemoryPagePolicy


namespace RE
{
	namespace BSScript
	{
		class SimpleAllocMemoryPagePolicy : public IMemoryPagePolicy
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__SimpleAllocMemoryPagePolicy;


			virtual ~SimpleAllocMemoryPagePolicy();	// 00

			// override (IMemoryPagePolicy)
			virtual void	Unk_01(void) override;	// 01
			virtual void	Unk_02(void) override;	// 02
			virtual void	Unk_03(void) override;	// 03
			virtual void	Unk_04(void) override;	// 04


			// members
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(SimpleAllocMemoryPagePolicy) == 0x28);
	}
}
