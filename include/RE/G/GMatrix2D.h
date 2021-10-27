#pragma once

namespace RE
{
	class GMatrix2D
	{
	public:
		GMatrix2D()
		{
			SetIdentity();
		}

		GMatrix2D& operator=(const GMatrix2D& a_rhs)
		{
			for (std::size_t i = 0; i < std::extent<decltype(data), 0>::value; ++i) {
				for (std::size_t j = 0; j < std::extent<decltype(data), 1>::value; ++j) {
					data[i][j] = a_rhs.data[i][j];
				}
			}
			return *this;
		}

		inline void SetMatrix(const GMatrix2D& a_matrix)
		{
			data[0][0] = a_matrix.data[0][0];
			data[0][1] = a_matrix.data[0][1];
			data[0][2] = a_matrix.data[0][2];
			data[1][0] = a_matrix.data[1][0];
			data[1][1] = a_matrix.data[1][1];
			data[1][2] = a_matrix.data[1][2];
		}

		inline void SetMatrix(float a_v0, float a_v1, float a_v2, float a_v3, float a_v4, float a_v5)
		{
			data[0][0] = a_v0;
			data[0][1] = a_v1;
			data[0][2] = a_v4;
			data[1][0] = a_v2;
			data[1][1] = a_v3;
			data[1][2] = a_v5;
		}

		void SetIdentity()
		{
			data[0][0] = 1.0f;
			data[0][1] = 0.0f;
			data[0][2] = 0.0f;
			data[1][0] = 0.0f;
			data[1][1] = 1.0f;
			data[1][2] = 0.0f;
		}

		float data[2][3];  // 00
	};
	static_assert(sizeof(GMatrix2D) == 0x18);
}
