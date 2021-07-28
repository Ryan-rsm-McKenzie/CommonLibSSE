#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
		class Object;
		struct IVMObjectBindInterface;

		class ObjectBindPolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__ObjectBindPolicy;

			virtual ~ObjectBindPolicy();  // 00

			// add
			virtual void Unk_01() = 0;  // 01
			virtual void Unk_02() = 0;  // 02
			virtual void Unk_03() = 0;  // 03
			virtual void Unk_04() = 0;  // 04
			virtual void Unk_05() = 0;  // 05
			virtual void Unk_06() = 0;  // 06
			virtual void Unk_07() = 0;  // 07
			virtual void Unk_08() = 0;  // 08
			virtual void Unk_09() = 0;  // 09
			virtual void Unk_0A() = 0;  // 0A
			virtual void Unk_0B() = 0;  // 0B
			virtual void Unk_0C() = 0;  // 0C

			void BindObject(BSTSmartPointer<Object>& a_objectPtr, VMHandle a_handle);

			// members
			IVirtualMachine*               vm;                   // 08
			IVMObjectBindInterface*        bindInterface;        // 10
			mutable BSSpinLock             attachedScriptsLock;  // 18
			BSTHashMap<VMHandle, UnkValue> attachedScripts;      // 20
		};
		static_assert(sizeof(ObjectBindPolicy) == 0x50);
	}
}
