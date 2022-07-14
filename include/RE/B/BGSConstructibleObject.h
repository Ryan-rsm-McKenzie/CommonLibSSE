#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSConstructibleObject : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSConstructibleObject;
		inline static constexpr auto VTABLE = VTABLE_BGSConstructibleObject;
		inline static constexpr auto FORMTYPE = FormType::ConstructibleObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct ConstructibleObjectData
		{
			std::uint16_t numConstructed;  // 0 - NAM1
		};
		static_assert(sizeof(ConstructibleObjectData) == 0x2);

		~BGSConstructibleObject() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		TESContainer            requiredItems;  // 20
		TESCondition            conditions;     // 38
		TESForm*                createdItem;    // 40 - CNAM
		BGSKeyword*             benchKeyword;   // 48 - BNAM
		ConstructibleObjectData data;           // 50
		std::uint16_t           pad52;          // 52
		std::uint32_t           unk54;          // 54
	};
	static_assert(sizeof(BGSConstructibleObject) == 0x58);
}
