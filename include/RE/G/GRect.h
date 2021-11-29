#pragma once

namespace RE
{
	template <class T>
	class GRect
	{
	public:
		// members
		T left;    // 00
		T top;     // ??
		T right;   // ??
		T bottom;  // ??
	};

	using GRectF = GRect<float>;
	static_assert(sizeof(GRectF) == 0x10);

	using GRectD = GRect<double>;
	static_assert(sizeof(GRectD) == 0x20);
}
