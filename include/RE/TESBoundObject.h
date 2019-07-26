#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESBoundObject

#include "RE/FormTypes.h"  // TESObjectREFR, BGSVoiceType
#include "RE/TESObject.h"  // TESObject


namespace RE
{
	class BSString;


	class TESBoundObject : public TESObject
	{
	public:
		inline static const void* RTTI = RTTI_TESBoundObject;


		struct ObjectBounds	// OBND
		{
			SInt16	x1;	// 0
			SInt16	y1;	// 2
			SInt16	z1;	// 4
			SInt16	x2;	// 6
			SInt16	y2;	// 8
			SInt16	z2;	// A
		};
		STATIC_ASSERT(sizeof(ObjectBounds) == 0xC);


		virtual ~TESBoundObject();																																			// 00

		// override (TESObject)
		virtual void			LoadBounds(TESFile* a_mod) override;																										// 26
		virtual bool			Has3D() override;																															// 27 - { return true; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void			Unk_44(void) override;																														// 44

		// add
		virtual void			SetVoiceType(BGSVoiceType* a_voiceType);																									// 48 - { return; }
		virtual BGSVoiceType*	GetVoiceType() const;																														// 49 - { return 0; }
		virtual void			Unk_4A(void);																																// 4A
		virtual void			Unk_4B(void);																																// 4B
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst);																					// 4C
		virtual void			Unk_4D(void);																																// 4D - "bool CanActivate(Actor* a_activator, bool, TESObjectREFR* a_toActivate, float)"?
		virtual void			OnRemovedFrom(TESObjectREFR* a_ref);																										// 4E - { return; }
		virtual void			Unk_4F(void);																																// 4F - { return; }
		virtual void			Unk_50(void);																																// 50 - { return; }
		virtual void			Unk_51(void);																																// 51 - { return; }
		virtual void			Unk_52(void);																																// 52 - { return; }


		// members
		ObjectBounds	objectBounds;	// 20 - OBND
		UInt32			pad2C;			// 2C
	};
	STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
}
