#pragma once

#include "skse64/GameFormComponents.h"  // TESFullName, TESModelTextureSwap, BGSDestructibleObjectForm, BGSOpenCloseForm, BGSKeywordForm

#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject

class BGSSoundDescriptorForm;
class BSString;
class TESWaterForm;


namespace RE
{
	class TESObjectREFR;


	class TESObjectACTI :
		public TESBoundAnimObject,
		public TESFullName,
		public TESModelTextureSwap,
		public BGSDestructibleObjectForm,
		public BGSOpenCloseForm,
		public BGSKeywordForm
	{
	public:
		enum { kTypeID = kFormType_Activator };


		virtual bool GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;


		// members
		BGSSoundDescriptorForm*	loopingSound;		// A8
		BGSSoundDescriptorForm*	activationSound;	// B0
		TESWaterForm*			waterType;			// B8
		UInt16					flags;				// C0
		UInt8					padC2[6];			// C2
	};
}
