#pragma once


namespace RE
{
	template <class T>
	class NiRect
	{
	public:
		NiRect(T a_left = T(0), T a_right = T(0), T a_top = T(0), T a_bottom = T(0)) :
			left(a_left),
			right(a_right),
			top(a_top),
			bottom(a_bottom)
		{}


		T GetWidth() const
		{
			return right > left ? (right - left) : (left - right);
		}


		T GetHeight() const
		{
			return top > bottom ? (top - bottom) : (bottom - top);
		}

	protected:
		T	left;	// 00
		T	right;	// ??
		T	top;	// ??
		T	bottom;	// ??
	};
	STATIC_ASSERT(sizeof(NiRect<float>) == 0x10);
}
