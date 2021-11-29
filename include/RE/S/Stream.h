#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/S/StreamBase.h"

namespace RE
{
	namespace BSResource
	{
		class AsyncStream;

		enum class SeekMode
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
			Stream(std::uint32_t a_totalSize);
			~Stream() override = default;  // 00

			// add
			virtual void      DoClone(BSTSmartPointer<Stream>& a_out) const = 0;                                           // 05
			virtual ErrorCode DoRead(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const = 0;             // 06
			virtual ErrorCode DoWrite(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const = 0;  // 07
			virtual ErrorCode DoSeek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const = 0;          // 08
			virtual ErrorCode DoSetEndOfStream();                                                                          // 09 - { return ErrorCode::kUnsupported; }
			virtual bool      DoGetName(BSFixedString& a_dst) const;                                                       // 0A - { a_dst = ""; return false; }
			virtual ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const;                              // 0B - { return ErrorCode::kUnsupported; }
		};
		static_assert(sizeof(Stream) == 0x10);
	}
}
