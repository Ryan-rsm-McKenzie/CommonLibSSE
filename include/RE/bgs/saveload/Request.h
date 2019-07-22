#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bgs__saveload__Request

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace bgs
	{
		namespace saveload
		{
			class Request : public BSIntrusiveRefCounted
			{
			public:
				inline static const void* RTTI = RTTI_bgs__saveload__Request;


				virtual ~Request();	// 00


				// members
				UInt32	unk0C;	// 0C
				UInt32	unk10;	// 10
				UInt32	pad14;	// 14
			};
			STATIC_ASSERT(sizeof(Request) == 0x18);
		}
	}
}
