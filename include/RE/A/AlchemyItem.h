#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MagicItem.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModelTextureSwap.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class AlchemyItem :
		public MagicItem,				   // 000
		public TESModelTextureSwap,		   // 090
		public TESIcon,					   // 0C8
		public BGSMessageIcon,			   // 0D8
		public TESWeightForm,			   // 0F0
		public BGSEquipType,			   // 100
		public BGSDestructibleObjectForm,  // 110
		public BGSPickupPutdownSounds	   // 120
	{
	public:
		inline static constexpr auto RTTI = RTTI_AlchemyItem;
		inline static constexpr auto FORMTYPE = FormType::AlchemyItem;

		enum class AlchemyFlag
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3,
			kMedicine = 1 << 16,
			kPoison = 1 << 17
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kMedicine = 1 << 29
			};
		};

		class Data	// ENIT
		{
		public:
			std::int32_t								 costOverride;		// 00
			stl::enumeration<AlchemyFlag, std::uint32_t> flags;				// 04
			SpellItem*									 addictionItem;		// 08
			float										 addictionChance;	// 10
			std::uint32_t								 pad14;				// 14
			BGSSoundDescriptorForm*						 consumptionSound;	// 18
		};
		static_assert(sizeof(Data) == 0x20);

		virtual ~AlchemyItem();	 // 00

		// override (MagicItem)
		virtual void					 InitializeData() override;												// 04
		virtual void					 ClearData() override;													// 05
		virtual void					 InitItemImpl() override;												// 13
		virtual MagicSystem::SpellType	 GetSpellType() const override;											// 53 - { return MagicType::kAlchemy; }
		virtual MagicSystem::CastingType GetCastingType() const override;										// 55 - { return CastType::kFireAndForget; }
		virtual MagicSystem::Delivery	 GetDelivery() const override;											// 57 - { return TargetType::kSelf; }
		virtual bool					 IsFood() const override;												// 5D - { return ((GetData()->flags) & 2) && !IsPoison(); }
		virtual bool					 IsPoison() const override;												// 61 - { return ((GetData()->flags) >> 17) & 1; }
		virtual bool					 IsMedicine() const override;											// 62 - { return ((GetData()->flags) >> 8) >> 8; }
		virtual ActorValue				 GetAssociatedSkill() const override;									// 66 - { return ActorValue::kConfidence; }
		virtual std::uint32_t			 GetChunkID() override;													// 68 - { return 'ENIT'; }
		virtual void					 CopyMagicItemData(MagicItem* a_src) override;							// 69
		virtual void					 LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID) override;	// 6A
		virtual const MagicItem::Data*	 GetData1() const override;												// 6C - { return &effectData; }
		virtual MagicItem::Data*		 GetData2() override;													// 6D - { return &effectData; }
		virtual std::uint32_t			 GetDataSize() const override;											// 6E - { return 0x20; }
		virtual void					 InitFromChunk(TESFile* a_mod) override;								// 6F
		virtual void					 InitChunk() override;													// 70

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		// members
		Data	data;		  // 138 - ENIT
		TESIcon messageIcon;  // 158
	};
	static_assert(sizeof(AlchemyItem) == 0x168);
}
