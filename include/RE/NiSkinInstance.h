#pragma once

#include "RE/NiSmartPointer.h"
#include "RE/NiObject.h"


namespace RE
{
	class NiAVObject;
	class NiTransform;
	class NiSkinData;
	class NiSkinPartition;


	class NiSkinInstance : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiSkinInstance;
		inline static const void* Ni_RTTI = NiRTTI_NiSkinInstance;


		virtual ~NiSkinInstance();													// 00

		// override (NiObject)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E - { return; }

		// add
		virtual void			Unk_25(void);										// 25

		static NiSkinInstance* Create();


		// members
		NiPointer<NiSkinData>		skinData;						// 10
		NiPointer<NiSkinPartition>	skinPartition;					// 18
		NiAVObject*					rootParent;						// 20
		NiAVObject**				bones;							// 28
		NiTransform**				worldTransforms;				// 30
		UInt32						frameID;						// 38
		UInt32						numMatrices;					// 3C
		UInt32						numRegisters;					// 40
		UInt32						aloocatedSize;					// 44
		void*						boneMatrices;					// 48
		void*						skinToWorldWorldToSkinMatrix;	// 50
		UInt64						unk58;							// 58
		CRITICAL_SECTION			lock;							// 60
	};
	STATIC_ASSERT(sizeof(NiSkinInstance) == 0x88);
}
