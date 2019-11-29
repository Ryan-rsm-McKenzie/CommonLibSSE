#include "RE/UIStringHolder.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	UIStringHolder* UIStringHolder::GetSingleton()
	{
		REL::Offset<UIStringHolder**> singleton(Offset::UIStringHolder::Singleton);
		return *singleton;
	}
}
