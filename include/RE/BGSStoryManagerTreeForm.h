#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class Condition;


	class BGSStoryManagerTreeForm : public TESForm
	{
	public:
		virtual ~BGSStoryManagerTreeForm();	// 00

		// add
		virtual void		Unk_3B(void);			// 3B - { return 0; }
		virtual void		Unk_3C(void);			// 3C - { return 0; }
		virtual Condition*	GetConditions() = 0;	// 3D
		virtual void		Unk_3E(void) = 0;		// 3E


		// members
		UInt32	unk20;	// 20
		UInt32	pad24;	// 24
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
