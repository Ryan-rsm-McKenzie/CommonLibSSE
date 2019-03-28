#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSScriptType.h"  // BSScriptType
#include "RE/BSSpinLock.h"  // BSSpinLock


namespace RE
{
	namespace BSScript
	{
		class BSScriptArray : public BSIntrusiveRefCounted
		{
		public:
			~BSScriptArray();


			// members
			BSScriptType	type;	// 08
			UInt32			len;	// 10
			UInt32			pad14;	// 14
			BSSpinLock		lock;	// 18

		private:
			void Dtor();
		};
		STATIC_ASSERT(sizeof(BSScriptArray) == 0x20);
	}
}
