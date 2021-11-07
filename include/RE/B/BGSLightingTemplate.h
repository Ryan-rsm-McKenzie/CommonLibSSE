#pragma once

#include "RE/B/BGSDirectionalAmbientLightingColors.h"
#include "RE/F/FormTypes.h"
#include "RE/I/InteriorData.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSLightingTemplate : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLightingTemplate;
		inline static constexpr auto VTABLE = VTABLE_BGSLightingTemplate;
		inline static constexpr auto FORMTYPE = FormType::LightingMaster;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSLightingTemplate() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		INTERIOR_DATA                       data;                              // 20 - DATA
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // 80 - DALC
	};
	static_assert(sizeof(BGSLightingTemplate) == 0xA0);
}
