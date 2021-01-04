#include "RE/L/Location.h"

namespace RE
{
	namespace BSResource
	{
		Location::Location() :
			mounted(false),
			pad09(0),
			pad0A(0),
			pad0C(0)
		{}

		Location::~Location()
		{
			if (mounted) {
				DoUnmount();
			}
		}

		ErrorCode Location::DoMount()
		{
			return ErrorCode::kNone;
		}

		void Location::DoUnmount()
		{
			return;
		}

		ErrorCode Location::DoCreateAsyncStream(const char*, BSTSmartPointer<AsyncStream>&, Location*&, bool)
		{
			return ErrorCode::kUnsupported;
		}

		ErrorCode Location::DoGetInfo1(const char*, Info&, Location*&)
		{
			return ErrorCode::kUnsupported;
		}

		ErrorCode Location::DoGetInfo2(const char*, Info&, LocationTraverser*)
		{
			return ErrorCode::kUnsupported;
		}

		ErrorCode Location::DoDelete(const char*)
		{
			return ErrorCode::kUnsupported;
		}

		const char* Location::DoGetName() const
		{
			return nullptr;
		}

		std::uint32_t Location::DoQBufferHint() const
		{
			return 0x80000;
		}

		std::uint32_t Location::DoGetMinimumAsyncPacketSize() const
		{
			return 0x80000;
		}

		ErrorCode Location::DoGetInfo(const char* a_path, Info& a_info, Location*& a_location)
		{
			return DoGetInfo1(a_path, a_info, a_location);
		}

		ErrorCode Location::DoGetInfo(const char* a_path, Info& a_info, LocationTraverser* a_traverser)
		{
			return DoGetInfo2(a_path, a_info, a_traverser);
		}
	}
}
