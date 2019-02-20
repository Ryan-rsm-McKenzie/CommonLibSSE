#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSStoryManagerTreeForm : public TESForm
	{
	public:
		enum { kTypeID = FormType::None };


		virtual ~BGSStoryManagerTreeForm();	// 00

		// add
		virtual void	Unk_3B(void);		// 3B - { return 0; }
		virtual void	Unk_3C(void);		// 3C - { return 0; }
		virtual void	Unk_3D(void);		// 3D - pure
		virtual void	Unk_3E(void);		// 3E - pure


		// members
		UInt64 unk20;	// 28
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
