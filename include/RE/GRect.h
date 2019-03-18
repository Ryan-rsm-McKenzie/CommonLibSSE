#pragma once


namespace RE
{
	template <class T>
	class GRect
	{
	public:
		// members
		T	left;	// 00
		T	top;	// ??
		T	right;	// ??
		T	bottom;	// ??
	};


	using GRectF = GRect<float>;
	STATIC_ASSERT(sizeof(GRectF) == 0x10);
}
