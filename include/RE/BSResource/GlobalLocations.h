#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSResource/Location.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	namespace BSResource
	{
		class GlobalLocations :
			public Location,						 // 00
			public BSTSingletonSDM<GlobalLocations>	 // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____GlobalLocations;


			struct Entry
			{
			public:
				// members
				Entry*	  next;		 // 00
				Location* location;	 // 08
				UInt32	  priority;	 // 10
				UInt32	  pad14;	 // 14
			};
			STATIC_ASSERT(sizeof(Entry) == 0x18);


			virtual ~GlobalLocations();	 // 00

			// override (Location)
			virtual ErrorCode DoMount() override;																											  // 01
			virtual void	  DoUnmount() override;																											  // 02
			virtual ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;		  // 03
			virtual ErrorCode DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;  // 04
			virtual ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;												  // 05
			virtual ErrorCode DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;													  // 06
			virtual ErrorCode DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;										  // 07
			virtual ErrorCode DoDelete(const char* a_path) override;																						  // 08


			// members
			UInt8			   pad11;		  // 11
			UInt16			   pad12;		  // 12
			mutable BSSpinLock lock;		  // 14
			UInt32			   pad1C;		  // 1C
			Entry*			   head;		  // 20
			Entry*			   pendingMount;  // 28
			Entry*			   free;		  // 30
		};
		STATIC_ASSERT(sizeof(GlobalLocations) == 0x38);
	}
}
