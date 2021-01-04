#pragma once

namespace RE
{
	class GMatrix2D
	{
	public:
		GMatrix2D() :
			data{ 0.0 }
		{}

		GMatrix2D& operator=(const GMatrix2D& a_rhs)
		{
			for (std::size_t i = 0; i < std::extent<decltype(data), 0>::value; ++i) {
				for (std::size_t j = 0; j < std::extent<decltype(data), 1>::value; ++j) {
					data[i][j] = a_rhs.data[i][j];
				}
			}
			return *this;
		}

		float data[2][3];  // 00
	};
	static_assert(sizeof(GMatrix2D) == 0x18);
}
