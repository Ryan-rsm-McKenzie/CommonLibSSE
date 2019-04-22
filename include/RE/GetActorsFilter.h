#pragma once


namespace ProcessLists
{
	class GetActorsFilter
	{
	public:
		virtual ~GetActorsFilter();		// 00

		// add
		virtual void Unk_01(void) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(GetActorsFilter) == 0x8);
}
