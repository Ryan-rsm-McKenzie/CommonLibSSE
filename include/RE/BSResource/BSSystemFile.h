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
				FILETIME	  accessTime;  // 00
				FILETIME	  modifyTime;  // 08
				FILETIME	  createTime;  // 10
				LARGE_INTEGER fileSize;	   // 18
			};
			static_assert(sizeof(Info) == 0x20);


			BSSystemFile();


			// members
			std::uint32_t flags;  // 00
			std::uint32_t pad04;  // 04
			HANDLE		  file;	  // 08
		};
		static_assert(sizeof(BSSystemFile) == 0x10);
	}
}
