#pragma once


namespace RE
{
	template <class Ty>
	class NiRect
	{
	public:
		NiRect(Ty a_left = Ty(0), Ty a_right = Ty(0), Ty a_top = Ty(0), Ty a_bottom = Ty(0))
		{
			left = a_left;
			right = a_right;
			top = a_top;
			bottom = a_bottom;
		}


		Ty GetWidth() const
		{
			return right > left ? (right - left) : (left - right);
		}


		Ty GetHeight() const
		{
			return top > bottom ? (top - bottom) : (bottom - top);
		}

	protected:
		Ty	left;	// 00
		Ty	right;	// 04
		Ty	top;	// 08
		Ty	bottom;	// 0C
	};
	STATIC_ASSERT(sizeof(NiRect<float>) == 0x10);
}
