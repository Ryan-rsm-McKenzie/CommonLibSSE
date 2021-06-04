#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class Object;
		class Variable;

		class IStackCallbackFunctor : public BSIntrusiveRefCounted
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IStackCallbackFunctor;

			IStackCallbackFunctor();
			virtual ~IStackCallbackFunctor() = default;  // 00

			// add
			virtual void operator()(Variable a_result) = 0;                       // 01
			virtual bool CanSave() const;                                         // 02 - { return false; }
			virtual void SetObject(const BSTSmartPointer<Object>& a_object) = 0;  // 03

			// members
			std::uint32_t pad0C;  // 0C
		};
		static_assert(sizeof(IStackCallbackFunctor) == 0x10);
	}
}
