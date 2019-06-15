#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSLensFlare

#include "RE/BSLensFlareRenderData.h"  // BSLensFlareRenderData
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSLensFlare :
		public TESForm,					// 00
		public BSLensFlareRenderData	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSLensFlare;


		enum { kTypeID = FormType::LensFlare };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSLensFlare();							// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
	};
	STATIC_ASSERT(sizeof(BGSLensFlare) == 0x40);
}
