#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/S/SpellItem.h"
#include "RE/T/TESModelTextureSwap.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class ScrollItem :
		public SpellItem,                  // 000
		public TESModelTextureSwap,        // 0E8
		public BGSDestructibleObjectForm,  // 120
		public BGSPickupPutdownSounds,     // 130
		public TESWeightForm,              // 148
		public TESValueForm                // 158
	{
	public:
		inline static constexpr auto RTTI = RTTI_ScrollItem;
		inline static constexpr auto VTABLE = VTABLE_ScrollItem;
		inline static constexpr auto FORMTYPE = FormType::Scroll;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~ScrollItem() override;  // 00

		// override (SpellItem)
		void                     InitItemImpl() override;                                               // 13
		MagicSystem::SpellType   GetSpellType() const override;                                         // 53 - { return MagicSystem::SpellType::kScroll; }
		MagicSystem::CastingType GetCastingType() const override;                                       // 55 - { return MagicSystem::CastingType::kFireAndForget; }
		bool                     GetSkillUsageData(SkillUsageData& a_data) const override;              // 60 - { return 0; }
		ActorValue               GetAssociatedSkill() const override;                                   // 66 - { return ActorValue::kNone; }
		void                     LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID) override;  // 6A
	};
	static_assert(sizeof(ScrollItem) == 0x168);
}
