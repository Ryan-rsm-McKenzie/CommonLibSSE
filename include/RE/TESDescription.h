#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class BSString;
	class TESForm;


	class TESDescription : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESDescription;


		virtual ~TESDescription();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		void			GetDescription(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType = 'CSED');


		// members
		UInt32	fileOffset;	// 08
		UInt32	tableIdx;	// 0C
	};
	STATIC_ASSERT(sizeof(TESDescription) == 0x10);
}
