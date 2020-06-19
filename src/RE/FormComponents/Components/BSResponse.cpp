#include "RE/FormComponents/Components/BSResponse.h"


namespace RE
{
	ResponseDictionary* ResponseDictionary::GetSingleton()
	{
		REL::Offset<ResponseDictionary**> singleton = REL::ID(517372);
		return *singleton;
	}
}
