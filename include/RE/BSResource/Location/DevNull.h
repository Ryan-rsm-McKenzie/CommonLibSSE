#pragma once

#include "RE/BSResource/Location.h"
#include "RE/BSResource/Stream.h"
#include "RE/BSTSingleton.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSResource
	{
		class DevNull :
			public Location,				 // 00
			public BSTSingletonSDM<DevNull>	 // 10
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____DevNull;


			struct NullStream : public Stream
			{
			public:
				virtual ~NullStream();	// 00

				// override (Stream)
				virtual ErrorCode DoOpen() override;																  // 01 - { return ErrorCode::kNone; }
				virtual void	  DoClose() override;																  // 02 - { return; }
				virtual void	  DoClone(BSTSmartPointer<Stream>& a_out) const override;							  // 05
				virtual ErrorCode DoRead(void* a_buffer, UInt64 a_toRead, UInt64& a_read) const override;			  // 06
				virtual ErrorCode DoWrite(const void* a_buffer, UInt64 a_toWrite, UInt64& a_written) const override;  // 07
				virtual ErrorCode DoSeek(UInt64 a_toSeek, SeekMode a_mode, UInt64& a_sought) const override;		  // 08
			};
			STATIC_ASSERT(sizeof(NullStream) == 0x10);


			virtual ~DevNull();	 // 00

			// override (Location)
			virtual ErrorCode DoMount() override;																									   // 01 - { return ErrorCode::kNone; }
			virtual void	  DoUnmount() override;																									   // 02 - { return; }
			virtual ErrorCode DoCreateStream(const char* a_path, BSTSmartPointer<Stream>& a_stream, Location*& a_location, bool a_readOnly) override;  // 03
			virtual ErrorCode DoTraversePrefix(const char* a_path, LocationTraverser& a_traverser) override;										   // 05 - { return ErrorCode::kNotExist; }


			// members
			UInt8					pad11;		 // 11
			UInt16					pad12;		 // 12
			UInt32					pad14;		 // 14
			BSTSmartPointer<Stream> nullReader;	 // 18
			BSTSmartPointer<Stream> nullWriter;	 // 20
		};
		STATIC_ASSERT(sizeof(DevNull) == 0x28);
	}
}
