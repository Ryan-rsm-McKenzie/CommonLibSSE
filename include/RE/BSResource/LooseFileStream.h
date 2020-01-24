#pragma once

#include "RE/BSResource/LooseFileStreamBase.h"
#include "RE/BSResource/Stream.h"


namespace RE
{
	namespace BSResource
	{
		class LooseFileLocation;


		class LooseFileStream :
			public LooseFileStreamBase,	// 10
			public Stream				// 00
		{
		public:
			virtual ~LooseFileStream();																					// 00

			// override (Stream)
			virtual ErrorCode	DoOpen() override;																		// 01
			virtual void		DoClose() override;																		// 02
			virtual ErrorCode	DoGetInfo(Info& a_info) override;														// 04
			virtual void		DoClone(BSTSmartPointer<Stream>& a_out) const override;									// 05
			virtual ErrorCode	DoRead(void* a_buffer, UInt64 a_toRead, UInt64& a_read) const override;					// 06
			virtual ErrorCode	DoWrite(const void* a_buffer, UInt64 a_toWrite, UInt64& a_written) const override;		// 07
			virtual ErrorCode	DoSeek(UInt64 a_toSeek, SeekMode a_mode, UInt64& a_sought) const override;				// 08
			virtual ErrorCode	DoSetEndOfStream() override;															// 09
			virtual bool		DoGetName(BSFixedString& a_dst) const override;											// 0A
			virtual ErrorCode	DoCreateAsync(BSTSmartPointer<BSResource::AsyncStream>& a_streamOut) const override;	// 0B


			// members
			LooseFileLocation*	location;	// 38
			UInt64				filePos;	// 40
			void*				buffer;		// 48
		};
		STATIC_ASSERT(sizeof(LooseFileStream) == 0x50);
	}
}
