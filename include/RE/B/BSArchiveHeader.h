#pragma once

namespace RE
{
	class BSArchiveHeader
	{
	public:
		struct ArchiveFlag
		{
		public:
			// members
			std::uint32_t flag;  // 0
		};
		static_assert(sizeof(ArchiveFlag) == 0x4);

		// members
		std::uint32_t tag;                   // 00
		std::uint32_t version;               // 04
		std::uint32_t headerSize;            // 08
		ArchiveFlag   flags;                 // 0C
		std::uint32_t directories;           // 10
		std::uint32_t files;                 // 14
		std::uint32_t directoryNamesLength;  // 18
		std::uint32_t fileNamesLength;       // 1C
		std::uint16_t archiveType;           // 20
		std::uint16_t pad22;                 // 22
	};
	static_assert(sizeof(BSArchiveHeader) == 0x24);
}
