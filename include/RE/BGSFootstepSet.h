#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSFootstepSet

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSFootstepSet : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSFootstepSet;


		enum { kTypeID = FormType::FootstepSet };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSFootstepSet();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSTArray<BGSFootstep*>	walkForwardSets;			// 20
		BSTArray<BGSFootstep*>	runForwardSets;				// 38
		BSTArray<BGSFootstep*>	walkForwardAlternateSets;	// 50
		BSTArray<BGSFootstep*>	runForwardAlternateSets;	// 68
		BSTArray<BGSFootstep*>	walkForwardAlternate2Sets;	// 80
	};
	STATIC_ASSERT(sizeof(BGSFootstepSet) == 0x98);
}
