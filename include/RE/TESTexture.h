#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString

class BSString;


namespace RE
{
	class TESTexture : public BaseFormComponent
	{
	public:
		virtual ~TESTexture();													// 00

		// override (BaseFormComponent)
		virtual void		Init() override;									// 01
		virtual void		ReleaseRefs() override;								// 02
		virtual void		CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual void		Unk_04(void);										// 04 - { return 0; }
		virtual void		GetNormalMapName(BSString* a_out);					// 05
		virtual const char*	GetSearchDir();										// 06


		// members
		BSFixedString icon;	// 08
	};
	STATIC_ASSERT(sizeof(TESTexture) == 0x10);
}
