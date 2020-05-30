#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSResource/StreamBase.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSResource
	{
		class AsyncStream;


		enum class SeekMode : UInt32
		{
			kSet = 0,
			kCur = 1,
			kEnd = 2
		};


		class Stream : public StreamBase
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__Stream;


			Stream();
			Stream(const Stream& a_rhs);
			Stream(Stream&& a_rhs);
			Stream(UInt32 a_totalSize);
			virtual ~Stream() = default;  // 00

			// add
			virtual void	  DoClone(BSTSmartPointer<Stream>& a_out) const = 0;							 // 05
			virtual ErrorCode DoRead(void* a_buffer, UInt64 a_toRead, UInt64& a_read) const = 0;			 // 06
			virtual ErrorCode DoWrite(const void* a_buffer, UInt64 a_toWrite, UInt64& a_written) const = 0;	 // 07
			virtual ErrorCode DoSeek(UInt64 a_toSeek, SeekMode a_mode, UInt64& a_sought) const = 0;			 // 08
			virtual ErrorCode DoSetEndOfStream();															 // 09 - { return ErrorCode::kUnsupported; }
			virtual bool	  DoGetName(BSFixedString& a_dst) const;										 // 0A - { a_dst = ""; return false; }
			virtual ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const;				 // 0B - { return ErrorCode::kUnsupported; }
		};
		STATIC_ASSERT(sizeof(Stream) == 0x10);
	}
}
