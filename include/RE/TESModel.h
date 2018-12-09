#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	class TESModel : public BaseFormComponent
	{
	public:
		// add
		virtual const char*	GetModelName() const;					// 04 - { return modelName.c_str(); }
		virtual void		SetModelName(const char* a_modelName);	// 05 - { modelName = name; }
		virtual void		Unk_06(void);							// 06

		
		// members
		BSFixedString	modelName;	// 08
		void*			unk10;		// 10 - NiTPointerMap <int, void *>
		void*			unk18;		// 18
		UInt16			unk20;		// 20
		UInt8			unk22;		// 22
		UInt8			unk23;		// 23
		UInt32			pad24;		// 24
	};
	STATIC_ASSERT(sizeof(TESModel) == 0x28);
}