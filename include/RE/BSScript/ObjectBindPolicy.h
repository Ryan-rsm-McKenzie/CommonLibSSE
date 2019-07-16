#pragma once

#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class Object;


		class ObjectBindPolicy
		{
		public:
			virtual ~ObjectBindPolicy();		// 00

			// add
			virtual void	Unk_01(void) = 0;	// 01
			virtual void	Unk_02(void) = 0;	// 02
			virtual void	Unk_03(void) = 0;	// 03
			virtual void	Unk_04(void) = 0;	// 04
			virtual void	Unk_05(void) = 0;	// 05
			virtual void	Unk_06(void) = 0;	// 06
			virtual void	Unk_07(void) = 0;	// 07
			virtual void	Unk_08(void) = 0;	// 08
			virtual void	Unk_09(void) = 0;	// 09
			virtual void	Unk_0A(void) = 0;	// 0A
			virtual void	Unk_0B(void) = 0;	// 0B
			virtual void	Unk_0C(void) = 0;	// 0C

			void BindObject(BSTSmartPointer<Object>& a_objectPtr, VMHandle a_handle);


			// members
			UInt64							unk08;	// 08
			UInt64							unk10;	// 10
			UInt64							unk18;	// 18
			BSTHashMap<UnkKey, UnkValue>	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(ObjectBindPolicy) == 0x50);
	}
}
