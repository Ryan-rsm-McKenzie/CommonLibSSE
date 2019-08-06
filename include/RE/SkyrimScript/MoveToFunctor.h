#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"  // SkyrimScript::DelayFunctor
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class MoveToFunctor : public DelayFunctor
		{
		public:
			virtual ~MoveToFunctor();													// 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 1; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 0; }
			virtual void					Unk_06(void) override;						// 06


			// members
			RefHandle									selfHandle;			// 10
			RefHandle									targetHandle;		// 14
			NiPoint3									targetPosition;		// 18
			NiPoint3									targetRotation;		// 24
			bool										unk30;				// 30
			bool										useOwnValues;		// 31 - true == use values from this object, false == calculate from target
			UInt16										pad32;				// 32
			UInt32										pad34;				// 34
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;		// 38
		};
		STATIC_ASSERT(sizeof(MoveToFunctor) == 0x40);
	}
}
