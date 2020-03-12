#pragma once

#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	namespace bgs
	{
		namespace saveload
		{
			class Request : public BSIntrusiveRefCounted
			{
			public:
				inline static constexpr auto RTTI = RTTI_bgs__saveload__Request;


				virtual ~Request();	 // 00


				// members
				UInt32 unk0C;  // 0C
				UInt32 unk10;  // 10
				UInt32 pad14;  // 14
			};
			STATIC_ASSERT(sizeof(Request) == 0x18);
		}
	}
}
