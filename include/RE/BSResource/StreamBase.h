#pragma once

#include "RE/BSResource/ErrorCodes.h"


namespace RE
{
	namespace BSResource
	{
		struct Info;


		class StreamBase
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__StreamBase;


			virtual ~StreamBase();							// 00

			// add
			virtual ErrorCode	DoOpen() = 0;				// 01
			virtual void		DoClose() = 0;				// 02
			virtual UInt64		DoGetKey() const;			// 03 - { return 0; }
			virtual ErrorCode	DoGetInfo(Info& a_info);	// 04 - { return ErrorCode::kUnsupported; }


			// members
			UInt32	totalSize;	// 08
			UInt32	flags;		// 0C
		};
		STATIC_ASSERT(sizeof(StreamBase) == 0x10);
	}
}
