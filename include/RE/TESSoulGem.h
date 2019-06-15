#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESSoulGem

#include "RE/FormTypes.h"  // FormType
#include "RE/SoulLevels.h"  // SoulLevel
#include "RE/TESObjectMISC.h"  // TESObjectMISC


namespace RE
{
	class TESSoulGem : public TESObjectMISC
	{
	public:
		inline static const void* RTTI = RTTI_TESSoulGem;


		enum { kTypeID = FormType::SoulGem };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCanHoldNPCSoul = 1 << 17
			};
		};


		virtual ~TESSoulGem();															// 00

		// override (TESObjectMISC)
		virtual void	InitDefaults() override;										// 04
		virtual void	LoadRecordByType(TESFile* a_mod, UInt32 a_recordType) override;	// 54
		virtual void	Unk_55(void) override;											// 55

		SoulLevel		GetContainedSoul() const;
		SoulLevel		GetMaximumCapacity() const;


		// members
		TESSoulGem*	linkedTo;			// 100 - NAM0
		SoulLevel	containedSoul;		// 108 - SOUL
		SoulLevel	maximumCapacity;	// 109 - SLCP
		UInt16		unk10A;				// 10A
		UInt32		unk10C;				// 10C
	};
	STATIC_ASSERT(sizeof(TESSoulGem) == 0x110);
}
