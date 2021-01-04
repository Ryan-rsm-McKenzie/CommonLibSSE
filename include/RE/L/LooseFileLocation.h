#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/L/Location.h"

namespace RE
{
	namespace BSResource
	{
		struct BSSystemDir
		{
		public:
			// members
			void*					 handle;					 // 000
			WinAPI::WIN32_FIND_DATAA findData;					 // 008
			char					 dirPath[WinAPI::MAX_PATH];	 // 148
			ErrorCode				 lastError;					 // 24C
			std::uint64_t			 entryPos;					 // 250
		};
		static_assert(sizeof(BSSystemDir) == 0x258);

		class LooseFileLocation : public Location
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__LooseFileLocation;

			virtual ~LooseFileLocation();  // 00

			// override (Location)
			virtual ErrorCode	  DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;		  // 03
			virtual ErrorCode	  DoCreateAsyncStream(const char* a_path, BSTSmartPointer<AsyncStream>& a_out, Location*& a_location, bool a_readOnly) override;  // 04
			virtual ErrorCode	  DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;												  // 05
			virtual ErrorCode	  DoGetInfo1(const char* a_path, Info& a_info, Location*& a_location) override;													  // 06
			virtual ErrorCode	  DoGetInfo2(const char* a_path, Info& a_info, LocationTraverser* a_traverser) override;										  // 07
			virtual ErrorCode	  DoDelete(const char* a_path) override;																						  // 08
			virtual const char*	  DoGetName() const override;																									  // 09 - { return directory.c_str(); }
			virtual std::uint32_t DoGetMinimumAsyncPacketSize() const override;																					  // 0B - { return minimumAsyncPacketSize; }

			// members
			BSFixedString prefix;				   // 10
			std::uint32_t minimumAsyncPacketSize;  // 18
			bool		  asyncSupported;		   // 1C
			std::uint8_t  pad1D;				   // 1D
			std::uint16_t pad1E;				   // 1E
		};
		static_assert(sizeof(LooseFileLocation) == 0x20);
	}
}
