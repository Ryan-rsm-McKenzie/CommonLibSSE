#pragma once

#include "RE/TESObject.h"  // TESObject

class BGSVoiceType;
class BSString;


namespace RE
{
	class TESObjectREFR;


	class TESBoundObject : public TESObject
	{
	public:
		struct Bound
		{
			UInt16	x;
			UInt16	y;
			UInt16	z;
		};


		// override (TESForm)
		virtual bool	Has3D() override;																																// 27 - { return true; }
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37

		// add
		virtual void			Unk_49(void);																															// 49 - { return; }
		virtual BGSVoiceType*	GetVoiceType() const;																													// 4A - { return nullptr; }
		virtual void			Unk_4B(void);																															// 4B
		virtual void			Unk_4C(void);																															// 4C - { return true; }
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk);																	// 4D
		virtual void			Unk_4E(void);																															// 4E
		virtual void			OnRemovedFrom(TESObjectREFR* a_ref);																									// 4F - { return; } TESAmmo=func
		virtual void			Unk_50(void);																															// 50 - { return; }
		virtual void			Unk_51(void);																															// 51 - { return; }
		virtual void			Unk_52(void);																															// 52 - { return; }
		virtual void			Unk_53(void);																															// 53 - { return; }


		Bound	bounds;		// 20
		Bound	bounds2;	// 26  (not 28!)
	};
	STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
}
