#pragma once

#include "RE/B/BSArchive.h"
#include "RE/B/BSFile.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class Archive :
		public BSArchive,   // 190
		public BSFile,      // 000
		public NiRefObject  // 180
	{
	public:
		inline static constexpr auto RTTI = RTTI_Archive;

		~Archive() override;  // 00

		// members
		std::uint64_t unk1C0;  // 1C0
		std::uint64_t unk1C8;  // 1C8
		std::uint64_t unk1D0;  // 1D0
		std::uint64_t unk1D8;  // 1D8
		std::uint64_t unk1E0;  // 1E0
		std::uint64_t unk1E8;  // 1E8
		std::uint64_t unk1F0;  // 1F0
		std::uint64_t unk1F8;  // 1F8
		std::uint64_t unk200;  // 200
		std::uint64_t unk208;  // 208
		std::uint64_t unk210;  // 210
		std::uint64_t unk218;  // 218
		std::uint64_t unk220;  // 220
		std::uint64_t unk228;  // 228
	};
	static_assert(sizeof(Archive) == 0x230);
}
