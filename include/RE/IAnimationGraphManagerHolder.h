#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	class BSAnimationGraphManager;
	class BShkbAnimationGraph;


	class IAnimationGraphManagerHolder
	{
	public:
		virtual ~IAnimationGraphManagerHolder();														// 00

		// add
		virtual bool	SendAnimationEvent(const BSFixedString& a_eventName);							// 01
		virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) = 0;	// 02 - BSTSmartPointer
		virtual void	Unk_03(void);																	// 03
		virtual void	Unk_04(void);																	// 04
		virtual bool	ConstructBShkbAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) = 0;	// 05
		virtual void	Unk_06(void);																	// 06
		virtual void	Unk_07(void);																	// 07
		virtual void	SinkAnimationGraphEvent(BSTSmartPointer<BShkbAnimationGraph>& a_animGraph);		// 08 - sinks the holder (TESObjectREFR) to the the source passed in
		virtual void	Unk_09(void);																	// 09
		virtual void	Unk_0A(void);																	// 0A
		virtual void	Unk_0B(void);																	// 0B
		virtual void	Unk_0C(void);																	// 0C
		virtual void	Unk_0D(void);																	// 0D
		virtual void	Unk_0E(void);																	// 0E
		virtual void	Unk_0F(void);																	// 0F
		virtual bool	GetAnimationVariableFloat(const BSFixedString& a_variableName, float& a_out);	// 10
		virtual bool	GetAnimationVariableInt(const BSFixedString& a_variableName, SInt32& a_out);	// 11
		virtual bool	GetAnimationVariableBool(const BSFixedString& a_variableName, bool& a_out);		// 12
	};
}
