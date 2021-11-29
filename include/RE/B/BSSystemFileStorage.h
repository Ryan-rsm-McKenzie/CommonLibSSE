#pragma once

#include "RE/B/BSStorage.h"

namespace RE
{
	class BSSystemFileStorage : public BSStorage
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSystemFileStorage;

		struct Attributes
		{
		public:
			enum class Error
			{
				kNone = 0,
				kFileNotFound = 2,
				kAlreadyExists = 3,
				kPathNotFound = 4,
				kWriteProtect = 5,
				kOther = 6,

				kErrorMask = 0x7FFFFFFF,

				kUnkFlag = 1 << 31  // top bit isn't part of the error, mask 0x7FFFFFFF to get the error
			};

			// members
			stl::enumeration<Error, std::uint32_t> lastError;  // 00
			std::uint32_t                          pad24;      // 04
			void*                                  handle;     // 08
		};
		static_assert(sizeof(Attributes) == 0x10);

		~BSSystemFileStorage() override;  // 00

		// override (BSStorage)
		std::size_t              GetSize() const override;                                                       // 01
		std::size_t              GetPosition() const override;                                                   // 02
		BSStorageDefs::ErrorCode Seek(std::size_t a_offset, BSStorageDefs::SeekMode a_seekMode) const override;  // 03
		BSStorageDefs::ErrorCode Read(std::size_t a_numBytes, std::byte* a_bytes) const override;                // 04
		BSStorageDefs::ErrorCode Write(std::size_t a_numBytes, const std::byte* a_bytes) override;               // 05

		bool IsGoodForRead() const;

		// members
		Attributes    attributes;   // 20
		bool          unk30;        // 30
		bool          unk31;        // 31
		bool          goodForRead;  // 32
		std::uint8_t  pad33;        // 33
		std::uint32_t pad34;        // 34
	};
	static_assert(sizeof(BSSystemFileStorage) == 0x38);
}
