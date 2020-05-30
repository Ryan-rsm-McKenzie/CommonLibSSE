#include "RE/NiRTTI.h"


namespace RE
{
	const char* NiRTTI::GetName() const
	{
		return name;
	}


	const NiRTTI* NiRTTI::GetBaseRTTI() const
	{
		return baseRTTI;
	}
}
