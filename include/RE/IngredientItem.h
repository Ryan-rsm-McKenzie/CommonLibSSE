#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IngredientItem

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSEquipType.h"  // BGSEquipType
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class IngredientItem :
		public MagicItem,						// 000
		public TESModelTextureSwap,				// 090
		public TESIcon,							// 0C8
		public TESWeightForm,					// 0D8
		public BGSEquipType,					// 0E8
		public BGSDestructibleObjectForm,		// 0F8
		public BGSPickupPutdownSounds,			// 108
		public TESValueForm						// 120
	{
	public:
		inline static const void* RTTI = RTTI_IngredientItem;


		enum { kTypeID = FormType::Ingredient };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct EffectData	// ENIT
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kNoAutoCalculation = 1 << 0,
				kFoodItem = 1 << 1,
				kReferencesPersist = 1 << 8
			};


			UInt32	ingredientValue;	// 00
			Flag	flags;				// 04
		};
		STATIC_ASSERT(sizeof(EffectData) == 0x8);


		virtual ~IngredientItem();													// 00

		// override (MagicItem)
		virtual void		InitDefaults() override;								// 04
		virtual void		ReleaseManagedData() override;							// 05
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;			// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;			// 0F
		virtual void		Unk_12(void) override;									// 12
		virtual void		InitItem() override;									// 13
		virtual MagicType	GetMagicType() const override;							// 53 - { return MagicType::kIngredient; }
		virtual CastType	GetCastType() const override;							// 55 - { return CastType::kFireAndForget; }
		virtual TargetType	GetTargetType() const override;							// 57 - { return TargetType::kSelf; }
		virtual bool		IsFoodItem() const override;							// 5D - { return (GetData()->flags >> 1) & 1; }
		virtual void		Unk_60(void) override;									// 60 - something about ingredient skill use
		virtual void		Unk_65(void) override;									// 65 - { return 4; } - GetNumIngredientSlots()?
		virtual ActorValue	GetActorValueType() const override;						// 66 - { return ActorValue::kConfidence; }
		virtual UInt32		GetDataSigniture() const override;						// 68 - { return 'ENIT'; }
		virtual void		CopyData(MagicItem* a_src) override;					// 69
		virtual void		LoadData(TESFile* a_mod, UInt32 a_signature) override;	// 6A
		virtual void*		GetData() override;										// 6C - { return &effectData; }
		virtual void*		GetData2() override;									// 6D - { return &effectData; }
		virtual UInt32		GetDataSize() const override;							// 6E - { return 0x8; }
		virtual void		LoadData(TESFile* a_mod) override;						// 6F
		virtual void		ByteSwapData() override;								// 70


		// members
		EffectData	effectData;	// 130
		UInt64		unk138;		// 138
	};
	STATIC_ASSERT(sizeof(IngredientItem) == 0x140);
}
