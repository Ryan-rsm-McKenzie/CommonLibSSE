#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"  // SkyrimScript::DelayFunctor


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}
	}


	namespace SkyrimScript
	{
		class RemoveItemFunctor : public DelayFunctor
		{
		public:
			virtual ~RemoveItemFunctor();			// 00

			// override (DelayFunctor)
			virtual void	Unk_01(void) override;	// 01
			virtual void	Unk_02(void) override;	// 02 - { return 1; }
			virtual void	Unk_04(void) override;	// 04
			virtual void	Unk_05(void) override;	// 05 - { return 24; }
			virtual void	Unk_06(void) override;	// 06


			// members
			RefHandle							removeFrom;	// 10
			RefHandle							moveTo;		// 14
			FormID								toRemove;	// 18
			SInt32								count;		// 1C
			bool								silent;		// 20
			UInt8								pad21;		// 21
			UInt16								pad22;		// 22
			UInt32								pad24;		// 24
			BSScript::Internal::VirtualMachine*	vm;			// 28
		};
		STATIC_ASSERT(sizeof(RemoveItemFunctor) == 0x30);
	}
}
