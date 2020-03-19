#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSTSmartPointer.h"
#include "RE/SkyrimScript/DelayFunctor.h"


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
			inline static constexpr auto RTTI = RTTI_SkyrimScript____DropObjectFunctor;


			virtual ~DropObjectFunctor();  // 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;														// 01
			virtual bool				   IsLatent() const override;													// 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;								// 04
			virtual FunctorType			   GetType() const override;													// 05 - { return 12; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, UInt32 a_arg2, bool& a_arg3) override;	// 06


			// members
			ObjectRefHandle							   dropper;		 // 10
			FormID									   itemToDrop;	 // 14
			UInt32									   countToDrop;	 // 18
			UInt32									   pad1C;		 // 1C
			BSTSmartPointer<BSScript::IVirtualMachine> vm;			 // 20
		};
		STATIC_ASSERT(sizeof(DropObjectFunctor) == 0x28);
	}
}
