#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/D/DelayFunctor.h"

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

			~DropObjectFunctor() override;  // 00

			// override (DelayFunctor)
			RE::BSScript::Variable operator()() override;                                                              // 01
			bool                   IsLatent() const override;                                                          // 02 - { return true; }
			bool                   SaveImpl(BSStorage& a_storage) const override;                                      // 04
			FunctorType            GetType() const override;                                                           // 05 - { return 12; }
			bool                   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06

			// members
			ObjectRefHandle                            dropper;      // 10
			FormID                                     itemToDrop;   // 14
			std::uint32_t                              countToDrop;  // 18
			std::uint32_t                              pad1C;        // 1C
			BSTSmartPointer<BSScript::IVirtualMachine> vm;           // 20
		};
		static_assert(sizeof(DropObjectFunctor) == 0x28);
	}
}
