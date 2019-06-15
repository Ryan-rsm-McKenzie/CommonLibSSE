#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiControllerManager

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiTArray.h"  // NiTArray
#include "RE/NiTimeController.h"  // NiTimeController


namespace RE
{
	class NiControllerSequence;


	class NiControllerManager : public NiTimeController
	{
	public:
		inline static const void* RTTI = RTTI_NiControllerManager;


		virtual ~NiControllerManager();											// 00

		// override (NiTimeController)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner) override;	// 17
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual void		LinkObject(NiStream* a_stream) override;			// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool		IsEqual(NiObject* a_object) override;				// 1C
		virtual void		ProcessClone(NiCloningProcess& a_cloning) override;	// 1D
		virtual void		PostLinkObject(NiStream& a_stream) override;		// 1E
		virtual void		Unk_24(void) override;								// 24 - { return this; }
		virtual void		Start(float a_time) override;						// 25
		virtual void		Stop() override;									// 26
		virtual void		Update(float a_time) override;						// 27
		virtual void		SetTarget(NiObjectNET* a_node) override;			// 28
		virtual void		Unk_2E(void) override;								// 2E

		// add
		virtual void		Unk_2F(void);										// 2F

		NiControllerSequence* GetSequenceByName(const BSFixedString& a_name);


		// members
		UInt64							unk48;		// 48
		UInt64							unk50;		// 50
		UInt64							unk58;		// 58
		UInt64							unk60;		// 60
		UInt64							unk68;		// 68
		UInt64							unk70;		// 70
		UInt64							unk78;		// 78
		UInt64							unk80;		// 80
		UInt64							unk88;		// 88
		UInt64							unk90;		// 90
		NiTArray<NiControllerSequence*>	sequences;	// 98
		UInt64							unkB0;		// B0
		UInt64							unkB8;		// B8
		UInt64							unkC0;		// C0
	};
	STATIC_ASSERT(sizeof(NiControllerManager) == 0xC8);
}
