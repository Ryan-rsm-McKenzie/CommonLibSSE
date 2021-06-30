#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/L/Location.h"
#include "RE/S/Stream.h"

namespace RE
{
	namespace BSResource
	{
		class DevNull :
			public Location,                 // 00
			public BSTSingletonSDM<DevNull>  // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____DevNull;

			struct NullStream : public Stream
			{
			public:
				~NullStream() override;  // 00

				// override (Stream)
				ErrorCode DoOpen() override;                                                                                // 01 - { return ErrorCode::kNone; }
				void      DoClose() override;                                                                               // 02 - { return; }
				void      DoClone(BSTSmartPointer<Stream>& a_out) const override;                                           // 05
				ErrorCode DoRead(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const override;             // 06
				ErrorCode DoWrite(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const override;  // 07
				ErrorCode DoSeek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const override;          // 08
			};
			static_assert(sizeof(NullStream) == 0x10);

			~DevNull() override;  // 00

			// override (Location)
			ErrorCode DoMount() override;                                                                                                      // 01 - { return ErrorCode::kNone; }
			void      DoUnmount() override;                                                                                                    // 02 - { return; }
			ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;  // 03
			ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;                                           // 05 - { return ErrorCode::kNotExist; }

			// members
			std::uint8_t            pad11;       // 11
			std::uint16_t           pad12;       // 12
			std::uint32_t           pad14;       // 14
			BSTSmartPointer<Stream> nullReader;  // 18
			BSTSmartPointer<Stream> nullWriter;  // 20
		};
		static_assert(sizeof(DevNull) == 0x28);
	}
}
