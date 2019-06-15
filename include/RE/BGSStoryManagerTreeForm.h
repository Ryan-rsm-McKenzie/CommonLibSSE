#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSStoryManagerTreeForm

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class Condition;


	class BGSStoryManagerTreeForm : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerTreeForm;


		virtual ~BGSStoryManagerTreeForm();								// 00

		// add
		virtual UInt32						GetNumChildren() const;		// 3B - { return 0; }
		virtual BGSStoryManagerEventNode*	GetNthChild(UInt32 a_idx);	// 3C - { return 0; }
		virtual Condition*					GetConditions() = 0;		// 3D
		virtual void						Unk_3E(void) = 0;			// 3E


		// members
		UInt32	unk20;	// 20
		UInt32	pad24;	// 24
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
