#pragma once

#include "RE/SkyrimScript/DelayFunctor.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
	}


	class TESForm;


	namespace SkyrimScript
	{
		class AttachAshPileFunctor : public DelayFunctor
		{
		public:
			virtual ~AttachAshPileFunctor();											// 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable&	Run(BSScript::Variable& a_result) override;	// 01
			virtual void					Unk_02(void) override;						// 02 - { return 0; }
			virtual void					Unk_04(void) override;						// 04
			virtual UInt32					GetFactoryType() const override;			// 05 - { return 14; }
			virtual void					Unk_06(void) override;						// 06


			// members
			RefHandle									actor;			// 10
			UInt32										pad14;			// 14
			TESForm*									ashPileBase;	// 18
			BSTSmartPointer<BSScript::IVirtualMachine>	virtualMachine;	// 20
		};
		STATIC_ASSERT(sizeof(AttachAshPileFunctor) == 0x28);
	}
}
