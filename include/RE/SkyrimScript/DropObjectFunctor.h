#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	namespace SkyrimScript
	{
		class DropObjectFunctor : public DelayFunctor
		{
		public:
			virtual ~DropObjectFunctor();												// 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 1; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 12; }
			virtual void					Unk_06(void) override;						// 06


			// members
			RefHandle									selfHandle;		// 10
			FormID										objectID;		// 14
			UInt32										count;			// 18
			UInt32										pad1C;			// 1C
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;	// 20
		};
		STATIC_ASSERT(sizeof(DropObjectFunctor) == 0x28);
	}
}
