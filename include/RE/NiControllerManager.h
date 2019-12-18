#pragma once

#include "RE/BSAnimNoteListener.h"
#include "RE/BSFixedString.h"
#include "BSTHashMap.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTArray.h"
#include "RE/NiTimeController.h"
#include "RE/NiTSet.h"


namespace RE
{
	class NiAVObjectPalette;
	class NiControllerSequence;


	class NiControllerManager : public NiTimeController
	{
	public:
		inline static const void* RTTI = RTTI_NiControllerManager;
		inline static const void* Ni_RTTI = NiRTTI_NiControllerManager;


		virtual ~NiControllerManager();														// 00

		// override (NiTimeController)
		virtual const NiRTTI*			GetRTTI() const override;							// 02
		virtual NiObject*				CreateClone(NiCloningProcess& a_cloning) override;	// 17
		virtual void					LoadBinary(NiStream& a_stream) override;			// 18
		virtual void					LinkObject(NiStream& a_stream) override;			// 19
		virtual bool					RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void					SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool					IsEqual(NiObject* a_object) override;				// 1C
		virtual void					ProcessClone(NiCloningProcess& a_cloning) override;	// 1D
		virtual void					PostLinkObject(NiStream& a_stream) override;		// 1E
		virtual NiControllerManager*	GetAsNiControllerManager() override;				// 24 - { return this; }
		virtual void					Start(float a_time) override;						// 25
		virtual void					Stop() override;									// 26
		virtual void					Update(float a_time) override;						// 27
		virtual void					SetTarget(NiObjectNET* a_node) override;			// 28
		virtual void					Unk_2E(void) override;								// 2E

		// add
		virtual void					Unk_2F(void);										// 2F

		NiControllerSequence* GetSequenceByName(const BSFixedString& a_name);


		// members
		NiTObjectArray<NiPointer<NiControllerSequence>>				sequences;		// 48
		void*														unk60;			// 60
		UInt64														unk68;			// 68
		BSTHashMap<BSFixedString, NiControllerSequence*>			sequenceMap;	// 70
		NiTPrimitiveArray<BSAnimNoteListener::BSAnimReceiverType*>*	unkA0;			// A0
		UInt64														unkA8;			// A8
		NiTObjectSet<NiPointer<NiControllerSequence>>				tempBlendSeqs;	// B0
		NiPointer<NiAVObjectPalette>								objectPalette;	// C0
	};
	STATIC_ASSERT(sizeof(NiControllerManager) == 0xC8);
}
