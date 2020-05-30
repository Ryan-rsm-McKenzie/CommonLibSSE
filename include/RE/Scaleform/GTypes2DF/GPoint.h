#pragma once


namespace RE
{
	template <class T>
	class GPoint
	{
	public:
		enum class BoundsType
		{
			kMin,
			kMax
		};

		// members
		T x;  // 00
		T y;  // ??
	};


	using GPointF = GPoint<float>;
	STATIC_ASSERT(sizeof(GPointF) == 0x8);

	using GPointD = GPoint<double>;
	STATIC_ASSERT(sizeof(GPointD) == 0x10);
}
