#pragma once

#include "skse64/GameRTTI.h"  // RTTI_AlchemyItem

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class AlchemyItem :
		public MagicItem,					// 000
		public TESModelTextureSwap,			// 090
		public TESIcon,						// 0C8
		public BGSMessageIcon,				// 0D8
		public TESWeightForm,				// 0F0
		public BGSEquipType,				// 100
		public BGSDestructibleObjectForm,	// 110
		public BGSPickupPutdownSounds		// 120
	{
	public:
		inline static const void* RTTI = RTTI_AlchemyItem;


		enum { kTypeID = FormType::AlchemyItem };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kMedicine = 1 << 29
			};
		};


		struct EffectData	// ENIT
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kNoAutoCalc = 1 << 0,
				kFoodItem = 1 << 1,
				kMedicine = 1 << 16,
				kPoison = 1 << 17
			};


			UInt32					value;				// 00
			Flag					flags;				// 04
			TESForm*				addiction;			// 08
			float					addictionChance;	// 10
			UInt32					unk14;				// 14
			BGSSoundDescriptorForm*	consumeSound;		// 18
		};
		STATIC_ASSERT(sizeof(EffectData) == 0x20);


		virtual ~AlchemyItem();														// 00

		// override (MagicItem)
		virtual void		InitDefaults() override;								// 04
		virtual void		ReleaseManagedData() override;							// 05
		virtual void		InitItem() override;									// 13
		virtual MagicType	GetMagicType() const override;							// 53 - { return MagicType::kAlchemy; }
		virtual CastType	GetCastType() const override;							// 55 - { return CastType::kFireAndForget; }
		virtual TargetType	GetTargetType() const override;							// 57 - { return TargetType::kSelf; }
		virtual bool		IsFoodItem() const override;							// 5D - { return ((GetData()->flags) & 2) && !IsPoison(); }
		virtual bool		IsPoison() const override;								// 61 - { return ((GetData()->flags) >> 17) & 1; }
		virtual bool		IsHealingItem() const override;							// 62 - { return ((GetData()->flags) >> 8) >> 8; }
		virtual ActorValue	GetActorValueType() const override;						// 66 - { return ActorValue::kConfidence; }
		virtual UInt32		GetDataSigniture() const override;						// 68 - { return 'ENIT'; }
		virtual void		CopyData(MagicItem* a_src) override;					// 69
		virtual void		LoadData(TESFile* a_mod, UInt32 a_signature) override;	// 6A
		virtual void*		GetData() override;										// 6C - { return &effectData; }
		virtual void*		GetData2(void) override;								// 6D - { return &effectData; }
		virtual UInt32		GetDataSize() const override;							// 6E - { return 0x20; }
		virtual void		LoadData(TESFile* a_mod) override;						// 6F
		virtual void		ByteSwapData() override;								// 70


		// members
		EffectData	effectData;	// 138 - ENIT
		TESIcon		unk158;		// 158
	};
	STATIC_ASSERT(sizeof(AlchemyItem) == 0x168);
}
