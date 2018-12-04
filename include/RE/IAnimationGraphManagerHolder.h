#pragma once

#include "RE/BSFixedString.h"  // BSFixedString

class BSAnimationGraphManager;


namespace RE
{
	class IAnimationGraphManagerHolder
	{
	public:
		virtual ~IAnimationGraphManagerHolder();														// 00

		// add
		virtual bool	SendAnimationEvent(const BSFixedString& a_eventName);							// 01
		virtual bool	GetAnimationGraphManager(BSAnimationGraphManager*& a_out) = 0;					// 02 - BSSmartPointer
		virtual void	Unk_03(void);																	// 03
		virtual void	Unk_04(void);																	// 04
		virtual void	Unk_05(void);																	// 05
		virtual void	Unk_06(void);																	// 06
		virtual void	Unk_07(void);																	// 07
		virtual void	Unk_08(void);																	// 08
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
