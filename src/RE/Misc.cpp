#include "RE/Misc.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void DebugNotification(const char* a_notification, void* a_arg2, bool a_arg3)
	{
		using func_t = function_type_t<decltype(&DebugNotification)>;
		REL::Offset<func_t*> func(Offset::DebugNotification);
		return func(a_notification, a_arg2, a_arg3);
	}


	bool WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		using func_t = function_type_t<decltype(&WorldPtToScreenPt3)>;
		REL::Offset<func_t*> func(Offset::WorldPtToScreenPt3);
		return func(a_worldToCamMatrix, a_port, a_in, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}
}
