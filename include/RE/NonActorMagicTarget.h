#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"
#include "RE/MagicTarget.h"


namespace RE
{
	class ActiveEffect;
	class TESObjectREFR;


	class NonActorMagicTarget :
		public BSExtraData,	 // 00
		public MagicTarget	 // 10
	{
	public:
		inline static constexpr auto RTTI = RTTI_NonActorMagicTarget;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kNonActorMagicTarget;


		virtual ~NonActorMagicTarget();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kNonActorMagicTarget; }

		// override (MagicTarget)
		virtual void						 Unk_01(void) override;			   // 01
		virtual TESObjectREFR*				 GetTargetStatsObject() override;  // 02 - { return targetObject; }
		virtual bool						 CanAddActiveEffect() override;	   // 06 - { return true; }
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() override;   // 07 - { return &activeEffects; }


		// members
		TESObjectREFR*				targetObject;	// 28
		BSSimpleList<ActiveEffect*> activeEffects;	// 30
	};
	STATIC_ASSERT(sizeof(NonActorMagicTarget) == 0x40);
}
