#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"  // SkyrimScript::DelayFunctor
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class SetMotionTypeFunctor : public DelayFunctor
		{
		public:
			virtual ~SetMotionTypeFunctor();											// 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 1; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 8; }
			virtual void					Unk_06(void) override;						// 06


			// members
			RefHandle									selfHandle;		// 10
			UInt32										motionType;		// 14
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;	// 18
			bool										allowActivate;	// 20
			UInt8										pad21;			// 21
			UInt16										pad22;			// 22
			UInt32										pad24;			// 24
		};
		STATIC_ASSERT(sizeof(SetMotionTypeFunctor) == 0x28);
	}
}
