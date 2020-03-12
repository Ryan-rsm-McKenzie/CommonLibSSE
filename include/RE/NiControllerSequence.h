#pragma once

#include "RE/BSFixedString.h"
#include "RE/MemoryManager.h"
#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTimeController.h"


namespace RE
{
	class NiAVObject;
	class NiBlendInterpolator;
	class NiControllerManager;
	class NiInterpController;
	class NiInterpolator;
	class NiTextKeyExtraData;


	class NiControllerSequence : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiControllerSequence;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiControllerSequence;


		enum class AnimState : UInt32
		{
			kInactive,
			kAnimating,
			kEaseIn,
			kEaseOut,
			kTransSource,
			kTransDest,
			kMorphSource
		};


		struct InterpArrayItem
		{
			NiPointer<NiInterpolator>	  interpolator;	 // 00
			NiPointer<NiInterpController> interpCtlr;	 // 08
			NiBlendInterpolator*		  blendInterp;	 // 10
			UInt8						  blendIdx;		 // 18
			UInt8						  pad19;		 // 19
			UInt16						  pad1A;		 // 1A
			UInt32						  pad1C;		 // 1C
		};
		STATIC_ASSERT(sizeof(InterpArrayItem) == 0x20);


		struct IDTag
		{
			BSFixedString avObjectName;	   // 00
			BSFixedString propertyType;	   // 08
			BSFixedString ctlrType;		   // 10
			BSFixedString ctlrID;		   // 18
			BSFixedString interpolatorID;  // 20
		};
		STATIC_ASSERT(sizeof(IDTag) == 0x28);


		virtual ~NiControllerSequence();  // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							   // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;   // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			   // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			   // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	   // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			   // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				   // 1C
		virtual void		  ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
		virtual void		  PostLinkObject(NiStream& a_stream) override;		   // 1E

		// add
		virtual bool Deactivate(float a_easeOutTime, bool a_transition);  // 25


		// members
		BSFixedString						name;			   // 10
		UInt32								arraySize;		   // 18
		UInt32								arrayGrowBy;	   // 1C
		SimpleArray<InterpArrayItem>		interpArray;	   // 20
		SimpleArray<IDTag>					idTagArray;		   // 28
		float								seqWeight;		   // 30
		UInt32								pad34;			   // 30
		NiPointer<NiTextKeyExtraData>		textKeys;		   // 38
		NiTimeController::CycleType			cycleType;		   // 40
		float								frequency;		   // 44
		float								beginKeyTime;	   // 48
		float								endKeyTime;		   // 4C
		float								lastTime;		   // 50
		float								weightedLastTime;  // 54
		float								lastScaledTime;	   // 58
		UInt32								pad5C;			   // 5C
		NiControllerManager*				owner;			   // 60
		AnimState							state;			   // 68
		float								offset;			   // 6C
		float								startTime;		   // 70
		float								endTime;		   // 74
		float								destFrame;		   // 78
		UInt32								pad7C;			   // 7C
		NiControllerSequence*				partnerSequence;   // 80
		BSFixedString						accumRootName;	   // 88
		NiAVObject*							accumRoot;		   // 90
		void*								unk98;			   // 98 - smart ptr
		SInt16								unkA0;			   // A0
		UInt16								unkA2;			   // A2
		UInt32								unkA4;			   // A4
		SimpleArray<NiPointer<NiRefObject>> unkA8;			   // A8
		UInt16								unkB0;			   // B0
		UInt8								unkB2;			   // B2
		UInt8								unkB3;			   // B3
		UInt32								unkB4;			   // B4
	};
	STATIC_ASSERT(sizeof(NiControllerSequence) == 0xB8);
}
