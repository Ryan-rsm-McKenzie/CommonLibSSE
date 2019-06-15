#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESTexture

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class BSString;


	class TESTexture : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESTexture;


		virtual ~TESTexture();													// 00

		// override (BaseFormComponent)
		virtual void		Init() override;									// 01
		virtual void		ReleaseRefs() override;								// 02
		virtual void		CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt32		GetSize();											// 04 - { return 0; }
		virtual void		GetNormalMapName(BSString* a_out);					// 05
		virtual const char*	GetSearchDir();										// 06


		// members
		BSFixedString texture;	// 08 - ICON
	};
	STATIC_ASSERT(sizeof(TESTexture) == 0x10);
}
