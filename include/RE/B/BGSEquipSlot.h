#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSEquipSlot : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEquipSlot;
		inline static constexpr auto VTABLE = VTABLE_BGSEquipSlot;
		inline static constexpr auto FORMTYPE = FormType::EquipSlot;

		enum class Flag  // DATA
		{
			kNone = 0,
			kUseAllParents = 1 << 0,
			kParentsOptional = 1 << 1,
			kItemSlot = 1 << 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSEquipSlot() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BSTArray<BGSEquipSlot*>               parentSlots;  // 20 - PNAM
		stl::enumeration<Flag, std::uint32_t> flags;        // 38 - DATA
		std::uint32_t                         pad3C;        // 3C
	};
	static_assert(sizeof(BGSEquipSlot) == 0x40);
}
