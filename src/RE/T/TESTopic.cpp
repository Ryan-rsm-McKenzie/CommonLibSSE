#include "RE/T/TESTopic.h"

namespace RE
{
	float TESTopic::GetPriority() const
	{
		return static_cast<float>(priorityAndJournalIndex >> (8 * 3));
	}
}
