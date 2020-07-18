#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/Memory/MemoryManager.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObject.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiTimeController.h"
#include "RE/NetImmerse/NiSmartPointer.h"


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


		enum class AnimState
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
		public:
			// members
			NiPointer<NiInterpolator>	  interpolator;	 // 00
			NiPointer<NiInterpController> interpCtlr;	 // 08
			NiBlendInterpolator*		  blendInterp;	 // 10
			std::uint8_t				  blendIdx;		 // 18
			std::uint8_t				  pad19;		 // 19
			std::uint16_t				  pad1A;		 // 1A
			std::uint32_t				  pad1C;		 // 1C
		};
		static_assert(sizeof(InterpArrayItem) == 0x20);


		struct IDTag
		{
		public:
			// members
			BSFixedString avObjectName;	   // 00
			BSFixedString propertyType;	   // 08
			BSFixedString ctlrType;		   // 10
			BSFixedString ctlrID;		   // 18
			BSFixedString interpolatorID;  // 20
		};
		static_assert(sizeof(IDTag) == 0x28);


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
		BSFixedString							   name;			  // 10
		std::uint32_t							   arraySize;		  // 18
		std::uint32_t							   arrayGrowBy;		  // 1C
		SimpleArray<InterpArrayItem>			   interpArray;		  // 20
		SimpleArray<IDTag>						   idTagArray;		  // 28
		float									   seqWeight;		  // 30
		std::uint32_t							   pad34;			  // 30
		NiPointer<NiTextKeyExtraData>			   textKeys;		  // 38
		NiTimeController::CycleType				   cycleType;		  // 40
		float									   frequency;		  // 44
		float									   beginKeyTime;	  // 48
		float									   endKeyTime;		  // 4C
		float									   lastTime;		  // 50
		float									   weightedLastTime;  // 54
		float									   lastScaledTime;	  // 58
		std::uint32_t							   pad5C;			  // 5C
		NiControllerManager*					   owner;			  // 60
		stl::enumeration<AnimState, std::uint32_t> state;			  // 68
		float									   offset;			  // 6C
		float									   startTime;		  // 70
		float									   endTime;			  // 74
		float									   destFrame;		  // 78
		std::uint32_t							   pad7C;			  // 7C
		NiControllerSequence*					   partnerSequence;	  // 80
		BSFixedString							   accumRootName;	  // 88
		NiAVObject*								   accumRoot;		  // 90
		void*									   unk98;			  // 98 - smart ptr
		std::int16_t							   unkA0;			  // A0
		std::uint16_t							   unkA2;			  // A2
		std::uint32_t							   unkA4;			  // A4
		SimpleArray<NiPointer<NiRefObject>>		   unkA8;			  // A8
		std::uint16_t							   unkB0;			  // B0
		std::uint8_t							   unkB2;			  // B2
		std::uint8_t							   unkB3;			  // B3
		std::uint32_t							   unkB4;			  // B4
	};
	static_assert(sizeof(NiControllerSequence) == 0xB8);
}
