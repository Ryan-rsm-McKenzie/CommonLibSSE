#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class IFuncCallQuery : public BSIntrusiveRefCounted
			{
			public:
				virtual ~IFuncCallQuery();		// 00

				// add
				virtual void Unk_01(void) = 0;	// 01


				// members
				UInt32 pad0C;	// 0C
			};
			STATIC_ASSERT(sizeof(IFuncCallQuery) == 0x10);
		}
	}
}
