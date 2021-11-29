#pragma once

namespace RE
{
	class GMatrix3D
	{
	public:
		GMatrix3D() :
			data{ 0.0 }
		{}

		GMatrix3D& operator=(const GMatrix3D& a_rhs)
		{
			for (std::size_t i = 0; i < std::extent<decltype(data), 0>::value; ++i) {
				for (std::size_t j = 0; j < std::extent<decltype(data), 1>::value; ++j) {
					data[i][j] = a_rhs.data[i][j];
				}
			}
			return *this;
		}

		float data[4][4];  // 00
	};
	static_assert(sizeof(GMatrix3D) == 0x40);
}
