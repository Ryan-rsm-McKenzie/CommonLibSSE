#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString

class BSString;


namespace RE
{
	class TESTexture : public BaseFormComponent
	{
	public:
		// add
		virtual void		Unk_04(void);						// 04
		virtual void		GetNormalMapName(BSString* out);	// 05
		virtual const char*	GetSearchDir();						// 06


		// members
		BSFixedString str;	// 08
	};
	STATIC_ASSERT(sizeof(TESTexture) == 0x10);
}