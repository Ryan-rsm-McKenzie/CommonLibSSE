#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/FormTypes.h"
#include "RE/MagicItem.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	class IngredientItem :
		public MagicItem,				   // 000
		public TESModelTextureSwap,		   // 090
		public TESIcon,					   // 0C8
		public TESWeightForm,			   // 0D8
		public BGSEquipType,			   // 0E8
		public BGSDestructibleObjectForm,  // 0F8
		public BGSPickupPutdownSounds,	   // 108
		public TESValueForm				   // 120
	{
	public:
		inline static constexpr auto RTTI = RTTI_IngredientItem;
		inline static constexpr auto FORMTYPE = FormType::Ingredient;


		enum class IngredientFlag : UInt32
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3,
			kReferencesPersist = 1 << 8
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kIngredientUse = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		class Data	// ENIT
		{
		public:
			SInt32		   costOverride;  // 00
			IngredientFlag flags;		  // 04
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		struct GameData
		{
			UInt16 knownEffectFlags;
			UInt16 playerUses;
		};
		STATIC_ASSERT(sizeof(GameData) == 0x4);


		virtual ~IngredientItem();	// 00

		// override (MagicItem)
		virtual void					 InitializeData() override;										 // 04
		virtual void					 ClearData() override;											 // 05
		virtual void					 SaveGame(BGSSaveFormBuffer* a_buf) override;					 // 0E
		virtual void					 LoadGame(BGSLoadFormBuffer* a_buf) override;					 // 0F
		virtual void					 Revert(BGSLoadFormBuffer* a_buf) override;						 // 12
		virtual void					 InitItemImpl() override;										 // 13
		virtual MagicSystem::SpellType	 GetSpellType() const override;									 // 53 - { return MagicSystem::SpellType::kIngredient; }
		virtual MagicSystem::CastingType GetCastingType() const override;								 // 55 - { return  MagicSystem::CastingType::kFireAndForget; }
		virtual MagicSystem::Delivery	 GetDelivery() const override;									 // 57 - { return MagicSystem::Delivery::kSelf; }
		virtual bool					 IsFood() const override;										 // 5D - { return (GetData()->flags >> 1) & 1; }
		virtual bool					 GetSkillUsageData(SkillUsageData& a_data) const override;		 // 60
		virtual UInt32					 GetMaxEffectCount() const override;							 // 65 - { return 4; }
		virtual ActorValue				 GetAssociatedSkill() const override;							 // 66 - { return ActorValue::kConfidence; }
		virtual UInt32					 GetChunkID() override;											 // 68 - { return 'ENIT'; }
		virtual void					 CopyMagicItemData(MagicItem* a_src) override;					 // 69
		virtual void					 LoadMagicItemChunk(TESFile* a_mod, UInt32 a_chunkID) override;	 // 6A
		virtual const MagicItem::Data*	 GetData1() const override;										 // 6C - { return &effectData; }
		virtual MagicItem::Data*		 GetData2() override;											 // 6D - { return &effectData; }
		virtual UInt32					 GetDataSize() const override;									 // 6E - { return 0x8; }
		virtual void					 InitFromChunk(TESFile* a_mod) override;						 // 6F
		virtual void					 InitChunk() override;											 // 70

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05


		// members
		Data	 data;		// 130 - ENIT
		GameData gamedata;	// 138
		UInt32	 pad13C;	// 13C
	};
	STATIC_ASSERT(sizeof(IngredientItem) == 0x140);
}
