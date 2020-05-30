#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSResource/Location.h"
#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	namespace BSResource
	{
		class GlobalPaths :
			public Location,					 // 00
			public BSTSingletonSDM<GlobalPaths>	 // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____GlobalPaths;


			virtual ~GlobalPaths();	 // 00

			// override (Location)
			virtual ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;		  // 03
			virtual ErrorCode DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;  // 04
			virtual ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;												  // 05
			virtual ErrorCode DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;													  // 06
			virtual ErrorCode DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;										  // 07
			virtual ErrorCode DoDelete(const char* a_path) override;																						  // 08


			// members
			UInt8					pad11;		   // 11
			UInt16					pad12;		   // 12
			UInt32					pad14;		   // 14
			BSTArray<BSFixedString> names;		   // 18
			Location*				rootLocation;  // 30
		};
		STATIC_ASSERT(sizeof(GlobalPaths) == 0x38);
	}
}
