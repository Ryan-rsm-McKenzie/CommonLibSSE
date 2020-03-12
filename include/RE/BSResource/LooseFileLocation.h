#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSResource/Location.h"


namespace RE
{
	namespace BSResource
	{
		struct BSSystemDir
		{
		public:
			// members
			HANDLE			 handle;			 // 000
			WIN32_FIND_DATAA findData;			 // 008
			char			 dirPath[MAX_PATH];	 // 148
			ErrorCode		 lastError;			 // 24C
			LARGE_INTEGER	 entryPos;			 // 250
		};
		STATIC_ASSERT(sizeof(BSSystemDir) == 0x258);


		class LooseFileLocation : public Location
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__LooseFileLocation;


			virtual ~LooseFileLocation();  // 00

			// override (Location)
			virtual ErrorCode	DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;			// 03
			virtual ErrorCode	DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;	// 04
			virtual ErrorCode	DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;													// 05
			virtual ErrorCode	DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;													// 06
			virtual ErrorCode	DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;											// 07
			virtual ErrorCode	DoDelete(const char* a_path) override;																							// 08
			virtual const char* DoGetName() const override;																										// 09 - { return directory.c_str(); }
			virtual UInt32		DoGetMinimumAsyncPacketSize() const override;																					// 0B - { return minimumAsyncPacketSize; }


			// members
			BSFixedString prefix;				   // 10
			UInt32		  minimumAsyncPacketSize;  // 18
			bool		  asyncSupported;		   // 1C
			UInt8		  pad1D;				   // 1D
			UInt16		  pad1E;				   // 1E
		};
		STATIC_ASSERT(sizeof(LooseFileLocation) == 0x20);
	}
}
