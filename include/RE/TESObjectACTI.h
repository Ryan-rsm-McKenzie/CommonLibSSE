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
		enum { kTypeID = FormType::Activator };


		virtual ~TESObjectACTI();																																		// 00

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;																												// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;																									// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;																									// 0F
		virtual void	InitItem() override;																															// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;																	// 4D


		// members
		BGSSoundDescriptorForm*	loopingSound;		// A8
		BGSSoundDescriptorForm*	activationSound;	// B0
		TESWaterForm*			waterType;			// B8
		UInt16					flags;				// C0
		UInt8					padC2[6];			// C2
	};
	STATIC_ASSERT(sizeof(TESObjectACTI) == 0xC8);
}
