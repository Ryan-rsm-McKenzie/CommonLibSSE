#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTSingleton.h"
#include "RE/L/Location.h"

namespace RE
{
	namespace BSResource
	{
		class GlobalLocations :
			public Location,                         // 00
			public BSTSingletonSDM<GlobalLocations>  // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____GlobalLocations;

			struct Entry
			{
			public:
				// members
				Entry*        next;      // 00
				Location*     location;  // 08
				std::uint32_t priority;  // 10
				std::uint32_t pad14;     // 14
			};
			static_assert(sizeof(Entry) == 0x18);

			~GlobalLocations() override;  // 00

			// override (Location)
			ErrorCode DoMount() override;                                                                                                             // 01
			void      DoUnmount() override;                                                                                                           // 02
			ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;         // 03
			ErrorCode DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;  // 04
			ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;                                                  // 05
			ErrorCode DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;                                                   // 06
			ErrorCode DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;                                          // 07
			ErrorCode DoDelete(const char* a_path) override;                                                                                          // 08

			// members
			std::uint8_t       pad11;         // 11
			std::uint16_t      pad12;         // 12
			mutable BSSpinLock lock;          // 14
			std::uint32_t      pad1C;         // 1C
			Entry*             head;          // 20
			Entry*             pendingMount;  // 28
			Entry*             free;          // 30
		};
		static_assert(sizeof(GlobalLocations) == 0x38);
	}
}
