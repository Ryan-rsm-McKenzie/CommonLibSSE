#pragma once

namespace RE
{
	namespace BSResource
	{
		struct FileID
		{
		public:
			// members
			std::uint32_t file;    // 0
			char          ext[4];  // 0
		};
		static_assert(sizeof(FileID) == 0x8);
	}
}
