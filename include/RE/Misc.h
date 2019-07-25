#pragma once


namespace RE
{
	class NiPoint3;
	template <class T> class NiRect;
	class Setting;


	Setting*	GetINISetting(const char* a_name);
	void		DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	bool		WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);
}
