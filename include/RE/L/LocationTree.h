#pragma once

#include "RE/L/Location.h"

namespace RE
{
	namespace BSResource
	{
		class LocationTree : public Location
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____LocationTree;

			virtual ~LocationTree();  // 00

			// override (Location)
			virtual ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;		  // 03
			virtual ErrorCode DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;  // 04
			virtual ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;												  // 05
			virtual ErrorCode DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;													  // 06
			virtual ErrorCode DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;										  // 07
			virtual ErrorCode DoDelete(const char* a_path) override;																						  // 08

			// members
			Location* lhs;	// 10
			Location* rhs;	// 18
		};
		static_assert(sizeof(LocationTree) == 0x20);
	}
}
