#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IAnimationGraphManagerHolder

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	class BSAnimationGraphManager;
	class BShkbAnimationGraph;


	class IAnimationGraphManagerHolder
	{
	public:
		inline static const void* RTTI = RTTI_IAnimationGraphManagerHolder;


		virtual ~IAnimationGraphManagerHolder();														// 00

		// add
		virtual bool	SendAnimationEvent(const BSFixedString& a_eventName);							// 01
		virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) = 0;	// 02
		virtual bool	SetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_in) = 0;	// 03
		virtual void	Unk_04(void);																	// 04 - { return 0; }
		virtual bool	ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) = 0;		// 05
		virtual void	Unk_06(void);																	// 06 - { return 1; }
		virtual void	Unk_07(void);																	// 07 - { return 1; }
		virtual void	SinkAnimationGraphEvent(BSTSmartPointer<BShkbAnimationGraph>& a_animGraph);		// 08 - { return 1; } - sinks the holder (TESObjectREFR) to the the source passed in
		virtual void	Unk_09(void);																	// 09 - { return; }
		virtual void	Unk_0A(void);																	// 0A - { return 0; }
		virtual void	Unk_0B(void);																	// 0B - { return; }
		virtual void	Unk_0C(void);																	// 0C - { return; }
		virtual void	Unk_0D(void);																	// 0D - { return; }
		virtual void	Unk_0E(void);																	// 0E - { return 1; }
		virtual void	Unk_0F(void);																	// 0F - { return 0; }
		virtual bool	GetAnimationVariableFloat(const BSFixedString& a_variableName, float& a_out);	// 10
		virtual bool	GetAnimationVariableInt(const BSFixedString& a_variableName, SInt32& a_out);	// 11
		virtual bool	GetAnimationVariableBool(const BSFixedString& a_variableName, bool& a_out);		// 12
	};
	STATIC_ASSERT(sizeof(IAnimationGraphManagerHolder) == 0x8);
}
