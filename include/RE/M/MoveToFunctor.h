#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/D/DelayFunctor.h"
#include "RE/N/NiPoint3.h"

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
			inline static constexpr auto RTTI = RTTI_SkyrimScript____MoveToFunctor;

			~MoveToFunctor() override;  // 00

			// override (DelayFunctor)
			RE::BSScript::Variable operator()() override;                                                              // 01
			bool                   IsLatent() const override;                                                          // 02 - { return true; }
			bool                   SaveImpl(BSStorage& a_storage) const override;                                      // 04
			FunctorType            GetType() const override;                                                           // 05 - { return 0; }
			bool                   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06

			// members
			ObjectRefHandle                            source;          // 10
			ObjectRefHandle                            destination;     // 14
			NiPoint3                                   offset;          // 18
			NiPoint3                                   rotationOffset;  // 24
			bool                                       matchRotation;   // 30
			bool                                       exactTranslate;  // 31
			std::uint16_t                              pad32;           // 32
			std::uint32_t                              pad34;           // 34
			BSTSmartPointer<BSScript::IVirtualMachine> vm;              // 38
		};
		static_assert(sizeof(MoveToFunctor) == 0x40);
	}
}
