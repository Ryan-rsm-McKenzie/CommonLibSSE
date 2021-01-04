#pragma once

#include "RE/B/BSPointerHandle.h"
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
		class SetPositionFunctor : public DelayFunctor
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript____SetPositionFunctor;

			virtual ~SetPositionFunctor();	// 00

			// override (SkyrimScript::DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;															   // 01
			virtual bool				   IsLatent() const override;														   // 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;									   // 04
			virtual FunctorType			   GetType() const override;														   // 05 - { return 6; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3) override;  // 06

			// members
			ObjectRefHandle							   objectToMove;  // 10
			NiPoint3								   newPosition;	  // 14
			BSTSmartPointer<BSScript::IVirtualMachine> vm;			  // 20
		};
		static_assert(sizeof(SetPositionFunctor) == 0x28);
	}
}
