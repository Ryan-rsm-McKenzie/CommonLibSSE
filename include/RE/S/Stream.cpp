#include "RE/S/Stream.h"

namespace RE
{
	namespace BSResource
	{
		Stream::Stream() :
			Stream(0)
		{}

		Stream::Stream(std::uint32_t a_totalSize) :
			StreamBase(a_totalSize)
		{}

		Stream::Stream(const Stream& a_rhs) :
			StreamBase(a_rhs)
		{}

		Stream::Stream(Stream&& a_rhs) :
			StreamBase(std::move(a_rhs))
		{}

		ErrorCode Stream::DoSetEndOfStream()
		{
			return ErrorCode::kUnsupported;
		}

		bool Stream::DoGetName(BSFixedString& a_dst) const
		{
			a_dst = "";
			return false;
		}

		ErrorCode Stream::DoCreateAsync(BSTSmartPointer<BSResource::AsyncStream>&) const
		{
			return ErrorCode::kUnsupported;
		}
	}
}
