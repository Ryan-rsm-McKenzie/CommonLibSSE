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
		class SendPlayerToJailFunctor : public DelayFunctor
		{
		public:
			enum class Flag : UInt32
			{
				kNone = 0,
				kRemoveInventory = 1 << 0,
				kRealJail = 1 << 1
			};


			virtual ~SendPlayerToJailFunctor();											// 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 1; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 19; }
			virtual void					Unk_06(void) override;						// 06


			// members
			FormID										faction;		// 10
			Flag										flags;			// 14
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;	// 18
		};
		STATIC_ASSERT(sizeof(SendPlayerToJailFunctor) == 0x20);
	}
}
