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
			for (UInt32 i = 0; i < 4; ++i) {
				for (UInt32 j = 0; j < 4; ++j) {
					data[i][j] = a_rhs.data[i][j];
				}
			}
			return *this;
		}


		float data[4][4];	// 00
	};
	STATIC_ASSERT(sizeof(GMatrix3D) == 0x40);
}
