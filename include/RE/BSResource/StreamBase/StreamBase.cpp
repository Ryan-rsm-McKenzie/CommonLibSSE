#include "RE/BSResource/StreamBase/StreamBase.h"


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


		StreamBase::StreamBase(std::uint32_t a_totalSize) :
			totalSize(a_totalSize),
			flags(0)
		{}


		std::uint64_t StreamBase::DoGetKey() const
		{
			return 0;
		}


		ErrorCode StreamBase::DoGetInfo(Info&)
		{
			return ErrorCode::kUnsupported;
		}


		std::uint32_t StreamBase::DecRef()
		{
			auto tmpFlags = this->flags;
			std::uint32_t prevFlags;
			std::uint32_t result;
			do {
				prevFlags = tmpFlags;
				result = tmpFlags - kRefCountBeg;
				tmpFlags = InterlockedCompareExchange(&flags, tmpFlags - kRefCountBeg, tmpFlags);
			} while (tmpFlags != prevFlags);
			return result & kRefCountMask;
		}


		std::uint32_t StreamBase::IncRef()
		{
			auto tmpFlags = this->flags;
			std::uint32_t prevFlags;
			std::uint32_t result;
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
