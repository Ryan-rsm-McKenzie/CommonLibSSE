#pragma once

namespace RE
{
	template <class T, class Allocator, class SizePolicy>
	struct GArrayDataBase
	{
	public:
		// members
		T*         data;    // 00
		UPInt      size;    // 08
		SizePolicy policy;  // 10
	};
}
