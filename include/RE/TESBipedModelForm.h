#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESBipedModelForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelRDT.h"  // TESModelRDT
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class TESBipedModelForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESBipedModelForm;


		struct Sexes
		{
			enum
			{
				kMale = 0,
				kFemale,
				kTotal
			};
		};


		virtual ~TESBipedModelForm();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		TESModelTextureSwap	worldModels[Sexes::kTotal];		// 08
		TESIcon				icons[Sexes::kTotal];			// 78
		BGSMessageIcon		messageIcons[Sexes::kTotal];	// 98
		TESModelRDT			modelRDT;						// C8
	};
	STATIC_ASSERT(sizeof(TESBipedModelForm) == 0xF0);
}
