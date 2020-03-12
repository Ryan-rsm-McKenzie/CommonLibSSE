#pragma once

#include "RE/BSResource/ErrorCodes.h"
#include "RE/BSTSmartPointer.h"
#include "RE/MemoryManager.h"


namespace RE
{
	namespace BSResource
	{
		class AsyncStream;
		class LocationTraverser;
		class Stream;
		struct Info;


		class Location
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__Location;


			Location();
			virtual ~Location();  // 00

			// add
			virtual ErrorCode	DoMount();																											   // 01 - { return ErrorCode::kNone; }
			virtual void		DoUnmount();																										   // 02 - { return; }
			virtual ErrorCode	DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) = 0;	   // 03
			virtual ErrorCode	DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly);  // 04 - { return ErrorCode::kUnsupported; }
			virtual ErrorCode	DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) = 0;											   // 05
			virtual ErrorCode	DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location);												   // 06 - { return ErrorCode::kUnsupported; }
			virtual ErrorCode	DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser);										   // 07 - { return ErrorCode::kUnsupported; }
			virtual ErrorCode	DoDelete(const char* a_path);																						   // 08 - { return ErrorCode::kUnsupported; }
			virtual const char* DoGetName() const;																									   // 09 - { return 0; }
			virtual UInt32		DoQBufferHint() const;																								   // 0A - { return 0x80000; }
			virtual UInt32		DoGetMinimumAsyncPacketSize() const;																				   // 0B - { return 0x80000; }

			TES_HEAP_REDEFINE_NEW();

			ErrorCode DoGetInfo(const char* a_path, Info& a_info, Location*& a_location);
			ErrorCode DoGetInfo(const char* a_path, Info& a_info, LocationTraverser* a_traverser);


			// members
			bool   mounted;	 // 08
			UInt8  pad09;	 // 09
			UInt16 pad0A;	 // 0A
			UInt32 pad0C;	 // 0C
		};
		STATIC_ASSERT(sizeof(Location) == 0x10);
	}
}
