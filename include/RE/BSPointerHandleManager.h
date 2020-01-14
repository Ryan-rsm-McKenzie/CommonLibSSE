#pragma once


namespace RE
{
	template <class T>
	class BSPointerHandleManager
	{
	public:
	};
	STATIC_ASSERT(sizeof(BSPointerHandleManager<void*>) == 0x1);
}
