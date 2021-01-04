#pragma once

namespace RE
{
	namespace BSResource
	{
		class BSSystemFile
		{
		public:
			struct Info
			{
			public:
				// members
				WinAPI::FILETIME accessTime;  // 00
				WinAPI::FILETIME modifyTime;  // 08
				WinAPI::FILETIME createTime;  // 10
				std::uint64_t	 fileSize;	  // 18
			};
			static_assert(sizeof(Info) == 0x20);

			BSSystemFile();

			// members
			std::uint32_t flags{ 1 };							 // 00
			std::uint32_t pad04{ 0 };							 // 04
			void*		  file{ WinAPI::INVALID_HANDLE_VALUE };	 // 08
		};
		static_assert(sizeof(BSSystemFile) == 0x10);
	}
}
