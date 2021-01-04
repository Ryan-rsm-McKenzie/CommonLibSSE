#include "RE/N/NiCamera.h"

namespace RE
{
	bool NiCamera::WorldPtToScreenPt3(const float a_matrix[4][4], const NiRect<float>& a_port, const NiPoint3& a_point, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		using func_t = decltype(&NiCamera::WorldPtToScreenPt3);
		REL::Relocation<func_t> func{ Offset::NiCamera::WorldPtToScreenPt3 };
		return func(a_matrix, a_port, a_point, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}
}
