#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSTSmartPointer.h"
#include "RE/NiPoint3.h"
#include "RE/SkyrimScript/DelayFunctor.h"


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


			virtual ~MoveToFunctor();  // 00

			// override (DelayFunctor)
			virtual RE::BSScript::Variable operator()() override;														// 01
			virtual bool				   IsLatent() const override;													// 02 - { return true; }
			virtual bool				   SaveImpl(BSStorage& a_storage) const override;								// 04
			virtual FunctorType			   GetType() const override;													// 05 - { return 0; }
			virtual bool				   LoadImpl(const BSStorage& a_storage, UInt32 a_arg2, bool& a_arg3) override;	// 06


			// members
			ObjectRefHandle							   source;			// 10
			ObjectRefHandle							   destination;		// 14
			NiPoint3								   offset;			// 18
			NiPoint3								   rotationOffset;	// 24
			bool									   matchRotation;	// 30
			bool									   exactTranslate;	// 31
			UInt16									   pad32;			// 32
			UInt32									   pad34;			// 34
			BSTSmartPointer<BSScript::IVirtualMachine> vm;				// 38
		};
		STATIC_ASSERT(sizeof(MoveToFunctor) == 0x40);
	}
}
