#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/L/LooseFileStreamBase.h"
#include "RE/S/Stream.h"

namespace RE
{
	namespace BSResource
	{
		class Location;

		class LooseFileStream :
			public LooseFileStreamBase,	 // 10
			public Stream				 // 00
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource____LooseFileStream;

			virtual ~LooseFileStream();	 // 00

			// override (Stream)
			virtual ErrorCode DoOpen() override;																				// 01
			virtual void	  DoClose() override;																				// 02
			virtual ErrorCode DoGetInfo(Info& a_info) override;																	// 04
			virtual void	  DoClone(BSTSmartPointer<Stream>& a_out) const override;											// 05
			virtual ErrorCode DoRead(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const override;				// 06
			virtual ErrorCode DoWrite(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const override;	// 07
			virtual ErrorCode DoSeek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const override;			// 08
			virtual ErrorCode DoSetEndOfStream() override;																		// 09
			virtual bool	  DoGetName(BSFixedString& a_dst) const override;													// 0A
			virtual ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const override;							// 0B

			static LooseFileStream* Create(BSFixedString a_prefix, BSFixedString a_dirName, BSFixedString a_fileName, std::uint32_t a_fileSize, bool a_readOnly, Location* a_location);

			// members
			Location*	  location;	 // 38
			std::uint64_t filePos;	 // 40
			void*		  buffer;	 // 48

		private:
			LooseFileStream* Ctor(const BSFixedString& a_prefix, const BSFixedString& a_dirName, const BSFixedString& a_fileName, std::uint32_t a_fileSize, bool a_readOnly, Location* a_location);
		};
		static_assert(sizeof(LooseFileStream) == 0x50);
	}
}
