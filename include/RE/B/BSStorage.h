#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	namespace BSStorageDefs
	{
		enum class ErrorCode;
		enum class SeekMode;
	}

	class BSStorage : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSStorage;

		struct UnkData
		{
		public:
			// members
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
			std::uint64_t unk10;  // 10
		};
		static_assert(sizeof(UnkData) == 0x18);

		virtual ~BSStorage();  // 00

		// add
		virtual std::size_t				 GetSize() const = 0;														// 01
		virtual std::size_t				 GetPosition() const = 0;													// 02
		virtual BSStorageDefs::ErrorCode Seek(std::size_t a_offset, BSStorageDefs::SeekMode a_seekMode) const = 0;	// 03
		virtual BSStorageDefs::ErrorCode Read(std::size_t a_numBytes, std::byte* a_bytes) const = 0;				// 04
		virtual BSStorageDefs::ErrorCode Write(std::size_t a_numBytes, const std::byte* a_bytes) = 0;				// 05

		// members
		std::uint32_t unk0C;  // 0C
		UnkData*	  unk10;  // 10
		std::uint64_t unk18;  // 18
	};
	static_assert(sizeof(BSStorage) == 0x20);
}
