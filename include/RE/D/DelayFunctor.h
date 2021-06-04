#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	namespace BSScript
	{
		class Variable;
	}

	class BSStorage;

	namespace SkyrimScript
	{
		class DelayFunctor : public BSIntrusiveRefCounted
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__DelayFunctor;

			enum class FunctorType
			{
				kMoveTo = 0,
				kSetPosition = 6,
				kSetMotionType = 8,
				kDropObject = 12,
				kAttachAshPile = 14,
				kSendPlayerToJail = 19,
				kRemoveItem = 24
			};

			virtual ~DelayFunctor();  // 00

			// add
			virtual RE::BSScript::Variable operator()() = 0;                                                          // 01
			virtual bool                   IsLatent() const = 0;                                                      // 02
			virtual bool                   WantsRequeue() const;                                                      // 03 - { return false; }
			virtual bool                   SaveImpl(BSStorage& a_storage) const;                                      // 04
			virtual FunctorType            GetType() const = 0;                                                       // 05
			virtual bool                   LoadImpl(const BSStorage& a_storage, std::uint32_t a_arg2, bool& a_arg3);  // 06

			// members
			VMStackID stackID;  // 0C
		};
		static_assert(sizeof(DelayFunctor) == 0x10);
	}
}
