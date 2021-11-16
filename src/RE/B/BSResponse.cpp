#include "RE/B/BSResponse.h"

namespace RE
{
	ResponseDictionary* ResponseDictionary::GetSingleton()
	{
		REL::Relocation<ResponseDictionary**> singleton{ REL::Offset(0x2FD4330) };
		return *singleton;
	}
}
