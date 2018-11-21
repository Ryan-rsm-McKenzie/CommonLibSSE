#pragma once

#include "skse64/GameTypes.h"


namespace RE
{
	class IAnimationGraphManagerHolder
	{
	public:
		virtual ~IAnimationGraphManagerHolder();

		virtual bool	SendAnimationEvent(const BSFixedString& a_eventName);						// 01
		virtual bool	GetAnimationGraphManager(void* a_out);										// 02 - Pure, BSAnimationGraphManagerPtr&
		virtual void	Unk_03(void);																// 03
		virtual void	Unk_04(void);																// 04
		virtual void	Unk_05(void);																// 05
		virtual void	Unk_06(void);																// 06
		virtual void	Unk_07(void);																// 07
		virtual void	Unk_08(void);																// 08
		virtual void	Unk_09(void);																// 09
		virtual void	Unk_0A(void);																// 0A
		virtual void	Unk_0B(void);																// 0B
		virtual void	Unk_0C(void);																// 0C
		virtual void	Unk_0D(void);																// 0D
		virtual void	Unk_0E(void);																// 0E
		virtual void	Unk_0F(void);																// 0F
		virtual bool	GetAnimationVariableFloat(const BSFixedString& variableName, float& out);	// 10
		virtual bool	GetAnimationVariableInt(const BSFixedString& variableName, SInt32& out);	// 11
		virtual bool	GetAnimationVariableBool(const BSFixedString& variableName, bool& out);		// 12
	};
}
