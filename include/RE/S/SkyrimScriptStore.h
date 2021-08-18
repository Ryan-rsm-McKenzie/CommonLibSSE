#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IStore.h"

namespace RE
{
	namespace BSResource
	{
		class Stream;
	}

	namespace SkyrimScript
	{
		class Store : public BSScript::IStore
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__Store;

			~Store() override;  // 00

			// override (BSScript::IStore)
			std::size_t              GetSize() const override;                                                       // 01
			std::size_t              GetPosition() const override;                                                   // 02
			BSStorageDefs::ErrorCode Seek(std::size_t a_offset, BSStorageDefs::SeekMode a_seekMode) const override;  // 03
			BSStorageDefs::ErrorCode Read(std::size_t a_numBytes, std::byte* a_bytes) const override;                // 04
			bool                     Open(const char* a_fileName) override;                                          // 06
			void                     Close(void) override;                                                           // 07
			const BSFixedString&     GetRelPath() override;                                                          // 08 - { return relPath; }
			bool                     HasOpenFile() override;                                                         // 09 - { return hasOpenFile; }
			bool                     FileIsGood() override;                                                          // 0A - { return fileIsGood; }
			void                     Unk_0B(void) override;                                                          // 0B

			// members
			std::uint64_t       unk20;        // 20
			BSResource::Stream* stream;       // 28
			BSFixedString       relPath;      // 30
			bool                hasOpenFile;  // 38
			bool                fileIsGood;   // 39
			std::uint16_t       pad3A;        // 3A
			std::uint32_t       pad3C;        // 3C
		};
		static_assert(sizeof(Store) == 0x40);
	}
}
