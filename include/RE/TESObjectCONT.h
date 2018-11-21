#pragma once

#include "skse64/GameFormComponents.h"  // TESContainer, TESFullName, TESModelTextureSwap, TESWeightForm, BGSDestructibleObjectForm, BGSOpenCloseForm

#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject


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
		enum { kTypeID = kFormType_Container };

		virtual bool GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;


		// members
		UInt8	unkB8;		// B8
		UInt8	unkB9;		// B9
		UInt8	padBA[6];	// BA
		UInt64	padC0;		// C0
		UInt64	padC8;		// C8
	};
}
