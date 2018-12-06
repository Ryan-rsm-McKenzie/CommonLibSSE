#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, TESWeightForm, BGSDestructibleObjectForm, BGSOpenCloseForm

#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESContainer.h"  // TESContainer


namespace RE
{
	class TESObjectCONT :
		public TESBoundAnimObject,			// 00
		public TESContainer,				// 30
		public TESFullName,					// 48
		public TESModelTextureSwap,			// 58
		public TESWeightForm,				// 90
		public BGSDestructibleObjectForm,	// A0
		public BGSOpenCloseForm				// B0
	{
	public:
		enum { kTypeID = FormType::Container };


		virtual ~TESObjectCONT();																																		// 00

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																												// 06
		virtual void	InitItem() override;																															// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;																	// 4C


		// members
		UInt8	unkB8;		// B8
		UInt8	unkB9;		// B9
		UInt8	padBA[6];	// BA
		UInt64	padC0;		// C0
		UInt64	padC8;		// C8
	};
	STATIC_ASSERT(sizeof(TESObjectCONT) == 0xD0);
}
