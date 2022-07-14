#pragma once

#include "RE/B/BSLensFlareRenderData.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSLensFlare :
		public TESForm,               // 00
		public BSLensFlareRenderData  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLensFlare;
		inline static constexpr auto VTABLE = VTABLE_BGSLensFlare;
		inline static constexpr auto FORMTYPE = FormType::LensFlare;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSLensFlare() override;  // 00

		// override (TESForm)
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13
	};
	static_assert(sizeof(BGSLensFlare) == 0x40);
}
