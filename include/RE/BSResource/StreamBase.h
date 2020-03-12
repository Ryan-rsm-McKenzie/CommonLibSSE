#pragma once

#include "RE/BSResource/ErrorCodes.h"
#include "RE/MemoryManager.h"


namespace RE
{
	namespace BSResource
	{
		struct Info;


		class StreamBase
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__StreamBase;


			enum : UInt32
			{
				kWritable = 1 << 0,
				kRefCountBeg = 0x1000,
				kRefCountMask = (UInt32)0xFFFFF000
			};


			StreamBase();
			StreamBase(const StreamBase& a_rhs);
			StreamBase(StreamBase&& a_rhs);
			StreamBase(UInt32 a_totalSize);
			virtual ~StreamBase() = default;  // 00

			// add
			virtual ErrorCode DoOpen() = 0;				// 01
			virtual void	  DoClose() = 0;			// 02
			virtual UInt64	  DoGetKey() const;			// 03 - { return 0; }
			virtual ErrorCode DoGetInfo(Info& a_info);	// 04 - { return ErrorCode::kUnsupported; }

			TES_HEAP_REDEFINE_NEW();


			UInt32 DecRef();
			UInt32 IncRef();
			bool   IsWritable() const;


			// members
			UInt32 totalSize;  // 08
			UInt32 flags;	   // 0C
		};
		STATIC_ASSERT(sizeof(StreamBase) == 0x10);
	}
}
