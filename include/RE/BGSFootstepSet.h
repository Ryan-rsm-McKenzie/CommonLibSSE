#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


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
