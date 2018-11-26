#include "RE/NiControllerSequence.h"

#include "RE/BSFixedString.h"  // BSFixedString


namespace RE
{
	const BSFixedString& NiControllerSequence::GetName() const
	{
		return name;
	}
}
