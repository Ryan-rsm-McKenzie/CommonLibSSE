#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class TESObjectSTAT;


	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		// add
		virtual TESObjectSTAT* GetMenuDisplayObject();	// 04 - { return worldStatic; }


		// members
		TESObjectSTAT* worldStatic;	// 08 - copyable
	};
	STATIC_ASSERT(sizeof(BGSMenuDisplayObject) == 0x10);
}
