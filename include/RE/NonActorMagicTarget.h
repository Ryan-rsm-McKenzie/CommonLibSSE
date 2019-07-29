#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/MagicTarget.h"  // MagicTarget


namespace RE
{
	class NonActorMagicTarget :
		public BSExtraData,	// 00
		public MagicTarget	// 10
	{
	public:
		inline static const void* RTTI = RTTI_BSExtraData;


		enum { kExtraTypeID = ExtraDataType::kNonActorMagicTarget };


		virtual ~NonActorMagicTarget();													// 00

		// override (BSExtraData)
		virtual ExtraDataType					GetType() const override;				// 01 - { return kNonActorMagicTarget; }

		// override (MagicTarget)
		virtual void							Unk_01(void) override;					// 01
		virtual Actor*							GetMagicTargetActor() const override;	// 02 - { return target; }
		virtual void							Unk_06(void) override;					// 06 - { return 1; }
		virtual BSSimpleList<ActiveEffect*>*	GetActiveEffects() override;			// 07 - { return &activeEffects; }


		// members
		Actor*						target;			// 28
		BSSimpleList<ActiveEffect*>	activeEffects;	// 30
	};
	STATIC_ASSERT(sizeof(NonActorMagicTarget) == 0x40);
}
