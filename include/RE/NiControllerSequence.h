#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiControllerSequence

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiControllerSequence : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiControllerSequence;


		virtual ~NiControllerSequence();											// 00

		// override (NiObject)
		virtual NiRTTI*			GetRTTI() override;									// 02
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner) override;	// 17
		virtual void			LoadBinary(NiStream* a_stream) override;			// 18
		virtual void			LinkObject(NiStream* a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;	// 1D
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E

		// add
		virtual void			Unk_25(void);										// 25


		// members
		BSFixedString	name;	// 10
		UInt64			unk18;	// 18
		UInt64			unk20;	// 20
		UInt64			unk28;	// 28
		UInt64			unk30;	// 30
		UInt64			unk38;	// 38
		UInt64			unk40;	// 40
		UInt64			unk48;	// 48
		UInt64			unk50;	// 50
		UInt64			unk58;	// 58
		UInt64			unk60;	// 60
		UInt64			unk68;	// 68
		UInt64			unk70;	// 70
		UInt64			unk78;	// 78
		UInt64			unk80;	// 80
		BSFixedString	unk88;	// 88
		UInt64			unk90;	// 90
		UInt64			unk98;	// 98
		UInt64			unkA0;	// A0
		UInt64			unkA8;	// A8
		UInt64			unkB0;	// B0
	};
	STATIC_ASSERT(sizeof(NiControllerSequence) == 0xB8);
}
