#pragma once

#include "RE/BSVolumetricLightingRenderData.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSVolumetricLighting :
		public TESForm,						   // 00
		public BSVolumetricLightingRenderData  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSVolumetricLighting;
		inline static constexpr auto FORMTYPE = FormType::VolumetricLighting;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSVolumetricLighting();  // 00

		// override (TESForm)
		virtual void ClearData() override;			 // 05 - { return; }
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13
	};
	STATIC_ASSERT(sizeof(BGSVolumetricLighting) == 0x50);
}
