#include "RE/BSResource/StreamBase.h"


namespace RE
{
	namespace BSResource
	{
		StreamBase::StreamBase() :
			totalSize(0),
			flags(0)
		{}


		StreamBase::StreamBase(const StreamBase& a_rhs) :
			totalSize(a_rhs.totalSize),
			flags(a_rhs.flags & ~kRefCountMask)
		{}


		StreamBase::StreamBase(StreamBase&& a_rhs) :
			totalSize(a_rhs.totalSize),
			flags(a_rhs.flags & ~kRefCountMask)
		{}


		StreamBase::StreamBase(UInt32 a_totalSize) :
			totalSize(a_totalSize),
			flags(0)
		{}


		UInt64 StreamBase::DoGetKey() const
		{
			return 0;
		}


		ErrorCode StreamBase::DoGetInfo(Info&)
		{
			return ErrorCode::kUnsupported;
		}


		UInt32 StreamBase::DecRef()
		{
			auto tmpFlags = this->flags;
			UInt32 prevFlags;
			UInt32 result;
			do {
				prevFlags = tmpFlags;
				result = tmpFlags - kRefCountBeg;
				tmpFlags = InterlockedCompareExchange(&flags, tmpFlags - kRefCountBeg, tmpFlags);
			} while (tmpFlags != prevFlags);
			return result & kRefCountMask;
		}


		UInt32 StreamBase::IncRef()
		{
			auto tmpFlags = this->flags;
			UInt32 prevFlags;
			UInt32 result;
			do {
				prevFlags = tmpFlags;
				result = tmpFlags + kRefCountBeg;
				tmpFlags = InterlockedCompareExchange(&flags, tmpFlags + kRefCountBeg, tmpFlags);
			} while (tmpFlags != prevFlags);
			return result & kRefCountMask;
		}


		bool StreamBase::IsWritable() const
		{
			return flags & kWritable;
		}
	}
}
