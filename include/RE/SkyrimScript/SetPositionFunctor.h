#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"  // SkyrimScript::DelayFunctor
#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class SetPositionFunctor : public DelayFunctor
		{
		public:
			virtual ~SetPositionFunctor();	// 00

			// override (SkyrimScript::DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 1; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 6; }
			virtual void					Unk_06(void) override;						// 06


			// members
			RefHandle									selfHandle;		// 10
			NiPoint3									targetPos;		// 14
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;	// 20
		};
		STATIC_ASSERT(sizeof(SetPositionFunctor) == 0x28);
	}
}
