#pragma once

#include "RE/FormTypes.h"  // Actor, TESForm
#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/NiRect.h"  // NiRect


namespace RE
{
	void	DebugNotification(const char* a_notification, void* a_arg2 = 0, bool a_arg3 = true);
	bool	WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
}
