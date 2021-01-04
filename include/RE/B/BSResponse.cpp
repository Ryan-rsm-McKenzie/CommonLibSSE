#include "RE/B/BSResponse.h"

namespace RE
{
	ResponseDictionary* ResponseDictionary::GetSingleton()
	{
		REL::Relocation<ResponseDictionary**> singleton{ REL::ID(517372) };
		return *singleton;
	}
}
