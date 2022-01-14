#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESProduceForm.h"

namespace RE
{
	class TESFlora :
		public TESObjectACTI,  // 00
		public TESProduceForm  // C8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFlora;
		inline static constexpr auto VTABLE = VTABLE_TESFlora;
		inline static constexpr auto FORMTYPE = FormType::Flora;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESFlora() override;  // 00

		// override (TESObjectACTI)
		bool Load(TESFile* a_mod) override;                                                                                                                            // 06
		void InitItemImpl() override;                                                                                                                                  // 13
		bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;                                                                                    // 4C
		bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;                                                    // 4D
	};
	static_assert(sizeof(TESFlora) == 0xE8);
}
