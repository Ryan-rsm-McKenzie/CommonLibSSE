#include "RE/S/StreamBase.h"

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
			stl::atomic_ref myFlags{ flags };
			std::uint32_t   expected;
			do {
				expected = myFlags;
			} while (!myFlags.compare_exchange_weak(expected, expected - kRefCountBeg));
			return (expected - kRefCountBeg) & kRefCountMask;
		}

		std::uint32_t StreamBase::IncRef()
		{
			stl::atomic_ref myFlags{ flags };
			std::uint32_t   expected;
			do {
				expected = myFlags;
			} while (!myFlags.compare_exchange_weak(expected, expected + kRefCountBeg));
			return (expected - kRefCountBeg) & kRefCountMask;
		}

		bool StreamBase::IsWritable() const
		{
			return static_cast<bool>(flags & kWritable);
		}
	}
}
