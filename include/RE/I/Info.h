#pragma once

namespace RE
{
	namespace BSResource
	{
		struct Info
		{
		public:
			// members
			WinAPI::FILETIME modifyTime;  // 00
			WinAPI::FILETIME createTime;  // 08
			std::uint64_t    fileSize;    // 10
		};
		static_assert(sizeof(Info) == 0x18);
	}
}
