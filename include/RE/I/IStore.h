#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSStorage.h"

namespace RE
{
	namespace BSScript
	{
		class IStore : public BSStorage
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IStore;

			~IStore() override;  // 00

			// override (BSStorage)
			BSStorageDefs::ErrorCode Write(std::size_t a_numBytes, const std::byte* a_bytes) override;  // 05

			// add
			virtual bool                 Open(const char* a_fileName) = 0;  // 06
			virtual void                 Close(void) = 0;                   // 07
			virtual const BSFixedString& GetRelPath() = 0;                  // 08
			virtual bool                 HasOpenFile(void) = 0;             // 09
			virtual bool                 FileIsGood(void) = 0;              // 0A
			virtual void                 Unk_0B(void) = 0;                  // 0B
		};
		static_assert(sizeof(IStore) == 0x20);
	}
}
